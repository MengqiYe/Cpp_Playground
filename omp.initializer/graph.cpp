//
// Created by elsey on 2022/2/22.
//
#include <malloc.h>
#include "graph.h"

ir_graph_t* create_ir_graph(struct context* context)
{
    ir_graph_t* ir_graph = (ir_graph_t*)malloc(sizeof(ir_graph_t));
    if (NULL == ir_graph)
    {
        return NULL;
    }

    ir_graph->attribute = (struct attribute*)malloc(sizeof(struct attribute));

    init_ir_graph(ir_graph, context);

    return ir_graph;
}

void init_ir_graph(ir_graph_t* graph, struct context* context)
{
    graph->tensor_list          = NULL;
    graph->node_list            = NULL;
    graph->input_nodes          = NULL;
    graph->output_nodes         = NULL;

    graph->tensor_num           = 0;
    graph->node_num             = 0;
    graph->input_num            = 0;
    graph->output_num           = 0;

    graph->subgraph_list        = create_vector(sizeof(struct subgraph*), NULL);

    graph->graph_layout         = TENGINE_LAYOUT_NCHW;
    graph->model_layout         = TENGINE_LAYOUT_NCHW;
    graph->model_format         = MODEL_FORMAT_TENGINE;

    graph->serializer           = NULL;
    graph->serializer_privacy   = NULL;

    graph->device               = NULL;
    graph->device_privacy       = NULL;

    graph->status               = GRAPH_STAT_CREATED;

    init_attribute(graph->attribute, context);
}

void init_attribute(ir_attribute_t* attribute, ir_context_t* context)
{
    attribute->status               = GRAPH_STAT_CREATED;
    attribute->priority             = 0;
    attribute->policy               = DEFAULT_POLICY;
    attribute->private_context      = 0;
    attribute->context              = context;
    attribute->device_privacy       = NULL;
    attribute->scheduler_privacy    = NULL;
}