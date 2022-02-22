//
// Created by elsey on 2022/2/21.
//

#include <cstdio>
#include <vector>
#include "init.h"
#include "graph.h"

typedef void* context_t;
typedef void* graph_t;
typedef void* tensor_t;
typedef void* node_t;

graph_t create_graph(context_t context, const char* model_format, const char* file_name, ...)
{

    ir_graph_t* ir_graph = create_ir_graph((struct context*)context);

    if (ir_graph == NULL)
    {
        return NULL;
    }

    return ir_graph;
}


int main(int argc, char *argv[]) {
    int classes = 80;
    graph_t graph = create_graph(nullptr, "tengine", param.model_file);


}












