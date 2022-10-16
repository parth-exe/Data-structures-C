#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph{
    int nodes;
    bool **edges;
}graph;
graph *create_graph(int nodes);
void clear_graph(graph *gr);
void print_graph(graph *gr);
bool add_edge(graph *gr, int from_node, int to_node);
bool has_edge(graph *gr, int from_node, int to_node);
int main(){
    graph *g1 = create_graph(7);
    add_edge(g1, 0, 1);
    add_edge(g1, 0, 3);
    add_edge(g1, 0, 2);
    add_edge(g1, 1, 2);
    add_edge(g1, 1, 0);
    add_edge(g1, 3, 1);
    add_edge(g1, 3, 4);
    print_graph(g1);
    clear_graph(g1);

    return 0;
}
graph *create_graph(int nodes){
    graph *gr = malloc(sizeof(*gr));
    if(gr == NULL){
        return NULL;
    }
    gr->nodes = nodes;

    gr->edges = calloc(sizeof(bool*), gr->nodes);
    if(gr->edges == NULL){
        free(gr);
        return NULL;
    }
    for(int i=0; i< gr->nodes; i++){
        gr->edges[i] = calloc(sizeof(bool), gr->nodes);
        if(gr->edges[i] == NULL){
            clear_graph(gr);
            return NULL;
        }
    }
    return gr;
}
void clear_graph(graph *gr){
    if(gr->edges == NULL){
        return;
    }
    for(int i=0;i<gr->nodes; i++){
        if(gr->edges[i] != NULL){
            free(gr->edges[i]);
        }
    }
    free(gr->edges);
}
void print_graph(graph *gr){
    printf("digraph {\n");
    for(int from=0; from<gr->nodes;from++){
        for(int to=0; to<gr->nodes; to++){
            if(gr->edges[from][to]){
                printf("%d -> %d; \n", from, to);
            }
        }
    }
    printf("}\n");
}
bool add_edge(graph *gr, int from_node, int to_node){
    if(has_edge(gr, from_node, to_node)){
        return false;
    }
    gr->edges[from_node][to_node] = true;
    return true;
}
bool has_edge(graph *gr, int from_node, int to_node){
    return gr->edges[from_node][to_node];
}