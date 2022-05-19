#ifndef ELEC_H
#define ELEC_H

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void init_opinion(struct graph_t*);
bool get_opinion(struct graph_t* g, int k);
int cellular_consensus(struct graph_t*, int k);
void next_step(struct graph_t* g);


#endif