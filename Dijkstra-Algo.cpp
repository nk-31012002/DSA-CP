/*
  Purpose : For finding the shortest path from a starting point (source) to every other point (node) in a weighted graph.

  Logic : 
  S0. Create a "distance" table : Keep track of the minimum distance from the starting node to every node.
  S1. Set the source distance to 0, all others to infinity (∞) because we don’t know their distances yet.
  S3. Use a priority queue (min-heap) to always explore the "closest" node first.
  S4. For each current node, update the distances to its neighboring nodes if a shorter path is found.
  S5. Mark nodes as visited once their shortest distance is finalized.
  S5. Repeat until all nodes are visited or the queue is empty.
  
*/
