#include "grafo.h"

struct grafo{
    int num_v;
    int num_a;
    int **matriz;
};

Grafo *GRAFOconstroi(int num_v){
    Grafo *g;
    g = malloc(sizeof(*g));
    g->num_v = num_v;
    g->num_a = 0;
    g->matriz = malloc(num_v * sizeof(int *));
    for(int i = 0; i < num_v ; i++){
        g->matriz[i] = malloc(sizeof(int) * num_v);
    }
    for(int i = 0; i < num_v; i++){
        for(int j = 0; j < num_v; j++){
            g->matriz[i][j] = 0;
        }
    }
    return g;
}
bool GRAFOvazio(Grafo *g){
    return g == NULL;
}
int GRAFO_get_num_aresta(Grafo *g){
    return g->num_a;
}
int GRAFO_get_num_vertice(Grafo *g){
    return g->num_v;
}

void GRAFOinsere_aresta(Grafo *g, vertex v, vertex w){
    if (g->matriz[v][w] == 0) {
        g->matriz[v][w] = 1;
        g->num_a++;
    }
}

void GRAFOremove_aresta(Grafo *g, vertex v, vertex w){
    if (g->matriz[v][w] == 1) {
        g->matriz[v][w] = 0;
        g->num_a--;
    }
}

void GRAFOimprime(Grafo *g){
    for (vertex v = 0; v < g->num_v; ++v) {
        printf( "%2d:", v);
        for (vertex w = 0; w < g->num_v; ++w)
            if (g->matriz[v][w] == 1)
                printf( " %2d", w);
        printf( "\n");
    }
}

void GRAFOdestroi(Grafo *g){
    for(int i = 0; i < g->num_v; i++){
        free(g->matriz[i]);
    }
    free(g->matriz);
    free(g);
}