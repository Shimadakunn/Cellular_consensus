Watts-Strogatz Topology and Cellular Consensus
========

Implementation of Watts and Strogatz&#39;s algorithm for network rewiring and Cellular Automata Consensus algorithm.

### This simulation goal is to study under which conditions interconnected nodes can agree on an opinion in the presence of malicious nodes.

The binary is built by typing "make".

strogatz:
=========

strogatz takes four arguments, the graph size (N), the number of edges per node in the original graph (K), and the probability of swapping (p) and probability of initial opinion (prob0).

You can add byzantin nodes which will interfere with the convergence of the opinion by adding two more arguments, the probabilty of node becoming byzantin (p_byz) and the probability of those nodes lying (p_lie).

The binary then prints out the graph in .dot format to stderr, so running

./strogatz 100 4 0.1 0.6 0.25 0.6

Will produce a graph with 100 nodes, and 4 connections for each node in the initial graph and then rewire them with probability 0.4 with initial opinion of 1 with probability 0.6. This network contains 25% of byzantin nodes which lies 60% of the time when they got asked they opinion. 

Then you will see in the folder ./graphs, the visualisation of the evolution of the opinion of your network

=========
It's an implementation based on this GitHub repository: https://github.com/andrewrch/strogatz

## The graph opinion before the consensus
![image](https://user-images.githubusercontent.com/89693356/231459205-3b678b40-cf92-4507-9f68-26f08eb948ba.png)

## The graph opinion after the consensus
![image](https://user-images.githubusercontent.com/89693356/231459464-8e478725-e78b-46f0-b4ff-72ef6117fe82.png)
