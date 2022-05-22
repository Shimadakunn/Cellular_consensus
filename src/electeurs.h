#ifndef ELEC_H
#define ELEC_H

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void init_opinion(struct graph_t*, float p0);
bool get_opinion(struct graph_t* g, int k);
void set_byzantins(struct graph_t* g, float p_byz);
bool get_byzantine(struct graph_t* g, int i);
void see_byzantin(struct graph_t* g);
void cellular_consensus(struct graph_t*, float p_lie);



#endif