#include "graph.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <assert.h>

void init_opinion(struct graph_t* g) //set random opinion for each node
{
    srand((unsigned)time(0));
    for(int i=0; i < g->size; i++){
        g->mat[i*g->size+i] = rand()%2;
    }
}

bool get_opinion(struct graph_t* g, int k){
    return g->mat[k*g->size+k];
}

int cellular_consensus(struct graph_t* g, int k){
    float opinion_0 = 0;
    float opinion_1 = 0;
    float degree = ((float)get_degree(g,k)) / 2;
    for(int i=k+1; i < g->size; i++){
        if(get_edge(g,i,k) && g->mat[i*g->size+i] == 0 ){
            opinion_0 ++ ;
        }
        else if(get_edge(g,i,k) && g->mat[i*g->size+i] == 1){
            opinion_1 ++ ;
        }
    }

    if(opinion_0 > degree) return 0;
    else if(opinion_1 > degree) return 1;
    else return -1;
}

void next_step(struct graph_t* g){
    for(int i=0; i < g->size; i++){
        // printf("Index: %d opinion: %d ", i, g->mat[i*g->size+i]);
        if(cellular_consensus(g,i) == 0) g->mat[i*g->size+i] = 0;
        else if(cellular_consensus(g,i) == 1) g->mat[i*g->size+i] = 1;
        // printf("voisin opinion: %d opinion n+1: %d \n", cellular_consensus(g,i), g->mat[i*g->size+i]);
    }
}
