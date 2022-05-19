CFLAGS := -Wall

all: strogatz print_L_C_curve print_histogram

strogatz: src/strogatz.c src/graph.c src/graph.h src/histogram.c src/histogram.h Makefile
	gcc $(CFLAGS) -o $@ $(filter %.c,$^)

print_L_C_curve: src/print_L_C_curve.c src/graph.c src/graph.h src/histogram.c src/histogram.h Makefile
	gcc $(CFLAGS) -o $@ $(filter %.c,$^)

print_histogram: src/print_histogram.c src/graph.c src/graph.h src/histogram.c src/histogram.h Makefile
	gcc $(CFLAGS) -o $@ $(filter %.c,$^)
