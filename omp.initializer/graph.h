//
// Created by elsey on 2022/2/22.
//

#ifndef CPP_PLAYGROUND_GRAPH_H
#define CPP_PLAYGROUND_GRAPH_H

#include "stdint.h"

#define TE_MAX_SHAPE_DIM_NUM        8

/* layout type, not real layout */
#define TENGINE_LAYOUT_NCHW         0
#define TENGINE_LAYOUT_NHWC         1

#define MODEL_FORMAT_UNKNOWN        0
#define MODEL_FORMAT_TENGINE        1
#define MODEL_FORMAT_CAFFE          2
#define MODEL_FORMAT_ONNX           3
#define MODEL_FORMAT_MXNET          4
#define MODEL_FORMAT_TENSORFLOW     5
#define MODEL_FORMAT_TFLITE         6
#define MODEL_FORMAT_DLA            7

enum graph_exec_stat
{
    GRAPH_STAT_CREATED,
    GRAPH_STAT_READY,
    GRAPH_STAT_RUNNING,
    GRAPH_STAT_DONE,
    GRAPH_STAT_ERROR
};

enum device_policy
{
    DEFAULT_POLICY,
    LATENCY_POLICY,
    LOW_POWER_POLICY
};

struct node;
struct tensor;
struct device;
struct attribute;

typedef struct attribute
{
    uint8_t status;
    uint8_t priority;
    uint8_t policy;
    uint8_t private_context;
    struct  context* context;
    void*   device_privacy;
    void*   scheduler_privacy;
} ir_attribute_t;

typedef struct context
{
    char* name;
    struct scheduler* scheduler;        //!< binding scheduler of this context
    struct device*    device;           //!< binding device of this context
    void*   default_options;             //<! default device options of this context
    void*  device_options;              //<! device options of this context
} ir_context_t;

using ir_tensor_t = struct tensor {
    uint16_t index;                          //!< the index of a tensor
    int16_t producer;                       //!< node id, '-1' means no producer
    int16_t *consumer;                       //!< consumer nodes array

    uint8_t reshaped;                       //!< the tensor's shape has changed
    uint8_t consumer_num;                   //!< count of consumer nodes
    uint8_t tensor_type;                    //!< tensor_type: { const, input, var, dep }
    uint8_t data_type;                      //!< data_type: { int8, uint8, fp32, fp16, int32 }
    uint8_t dim_num;                        //!< count of dimensions
    uint8_t elem_size;                      //!< size of single element
    uint8_t subgraph_num;                   //!< count of all subgraph those will waiting this tensor ready
    uint8_t free_host_mem;                  //!< should free host memory?
    uint8_t internal_allocated;             //!< how memory is allocated?
    uint8_t layout;                         //!< tensor layout: { TENGINE_LAYOUT_NCHW, TENGINE_LAYOUT_NHWC }

    uint16_t quant_param_num;                //!< quantization dimension
    uint32_t elem_num;                       //!< count of total elements
    int dims[TE_MAX_SHAPE_DIM_NUM];          //!< shape dimensions

    /*!
     * @union anonymity data pointer
     * @brief give useful pointer pointer
     */
    union {
        void *data;
        int8_t *i8;
        uint8_t *u8;
        float *f32;
        uint16_t *f16;
        int32_t *i32;
    };

    char *name;                             //!< tensor name

    /*!
     * @union anonymity quantization scale union
     * @brief scale or its array
     */
    union {
        float *scale_list;
        float scale;
    };

    /*!
     * @union anonymity quantization zero point union
     * @brief zero point or its array
     */
    union {
        int zero_point;
        int *zp_list;
    };

    struct dev_mem *dev_mem;
    uint8_t *subgraph_list;                 //!< subgraph index list of those subgraph will waiting this tensor ready
};

using ir_graph_t = struct graph {
    struct tensor **tensor_list; //!< the tensor list of a graph
    struct node **node_list;     //!< the node list of a graph
    int16_t *input_nodes;        //!< input nodes index array of a graph
    int16_t *output_nodes;       //!< output nodes index array of a graph

    uint16_t tensor_num; //!< the count of all graph tensor
    uint16_t node_num;   //!< the count of all graph node
    uint16_t input_num;  //!< input nodes index count of a graph
    uint16_t output_num; //!< input nodes index count of a graph

    int8_t graph_layout; //!< the data layout of a graph
    int8_t model_layout; //!< model layout of graph source model
    int8_t model_format; //!< model format of graph source model

    uint8_t status; //!< the status of graph

    struct serializer *serializer; //!< serializer of graph
    void *serializer_privacy;      //!< privacy data of serializer

    struct device *device; //!< assigned nn_device for this graph
    void *device_privacy;  //!< privacy data of device

    struct attribute *attribute; //<! attribute of graph

    struct vector *subgraph_list; //!< subgraph list of this graph
};

using vector_t = struct vector
{
    int elem_size;                  //!< elements size which will be pushed into vector
    int elem_num;                   //!< current counter of inserted elements

    int entry_size;                 //!< size of inside vector header entry
    int space_num;                  //!< the allocated elements counter, which should greater equal to 'elem_num'
    int ahead_num;                  //!< allocated step when vector is full
    void* real_mem;                 //!< real aligned memory address which point to vector entry
    void* mem;                      //!< visual aligned address which point to the very begging of elements
    void (*free_func)(void*);       //!< elements free function, will be called when release elements or vector
};

struct graph *create_ir_graph(struct context *context);

void init_ir_graph(ir_graph_t *graph, struct context *context);

void init_attribute(ir_attribute_t* attribute, struct context* context);

vector_t* create_vector(int elem_size, void (*free_func)(void*));

#endif //CPP_PLAYGROUND_GRAPH_H
