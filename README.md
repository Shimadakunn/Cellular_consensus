Watts-Strogatz Topology and Cellular Consensus
========

Implementation of Watts and Strogatz&#39;s algorithm for network rewiring and Cellular Automata Consensus algorithm

The binary is built by typing "make".

strogatz:
=========

strogatz takes four arguments, the graph size (N), the number of edges per node in the original graph (K), and the probability of swapping (p) and probability of initial opinion (p0).

The binary then prints out the graph in .dot format to stderr, so running

./strogatz 100 4 0.1 0.6

Will produce a graph with 100 nodes, and 4 connections for each node in the initial graph and then rewire them with probability with initial opinion of 1 with probability.

Then you will see in the folder ./graphs, the visualisation of the evolution of the opinion of your network

=========
It's an implementation based on this GitHub repository: https://github.com/andrewrch/strogatz