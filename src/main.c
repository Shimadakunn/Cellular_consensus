#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "electeurs.h"

static void print_usage(FILE *f)
{
  fprintf(f, "Usage: ./strogatz num_vertices edges_per_vertex prob_of_swap\n\n");
  fprintf(f, "  num_vertices - an int\n");
  fprintf(f, "  edges_per_vertex - an int\n");
  fprintf(f, "  prob_of_swap - a float between 0 and 1\n");
}

int main(int argc, char** argv)
{
  int num_vertices, edges_per_vertex;
  float prob_of_swap;
  struct graph_t *g;

  if (argc < 4)
    goto err_usage;
  if (sscanf(argv[1], "%i", &num_vertices) != 1)
    goto err_usage;
  if (sscanf(argv[2], "%i", &edges_per_vertex) != 1)
    goto err_usage;
  if (sscanf(argv[3], "%f", &prob_of_swap) != 1)
    goto err_usage;

  if (edges_per_vertex % 2) {
    fprintf(stdout, "edges_per_vertex should be even\n");
    return EXIT_FAILURE;
  }

  g = build_regular_graph(num_vertices, edges_per_vertex);
  randomise_graph(g, prob_of_swap);

  init_opinion(g);
  printf("\n === Apres initialisation de l'opinion ===\n");
  for(int i = 0; i < num_vertices*num_vertices; i++){
        printf("%d ", g->mat[i]);
        if(i%num_vertices == num_vertices-1) printf("\n");
  }

  printf("\n === Opinion === \n");
  for(int i = 0; i < num_vertices; i++){
    printf("%d: %d || ", i, g->mat[i*g->size+i]);
  }

  for(int i = 0; i < 10000; i++){
      next_step(g);
  }

  print_graph(stderr, g);
  
  delete_graph(g);
  return 0;

err_usage:
  
  return EXIT_FAILURE;
}
