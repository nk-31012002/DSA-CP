/*
              
Task:
1. Given DAG(u->v)
2. Return topological sort--->means Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.

Logic : Topological Sorting (Kahn’s Algorithm - BFS approach):-
S1. For each node count the number of incoming edges(in-degree).
S2. Add all nodes with 0 in-degree to a queue.
S3. Remove a node from the queue and add it to the topological order.
S3. Decrease the in-degree of its neighbors by 1.
S4. If any neighbor's in-degree becomes 0, push it to the queue.
S5. Check for Cycles : If the number of nodes in the topological order is less than the total nodes, the graph has a cycle.

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int V, vector<vector<int>> &adj){
  vector<int> in_degree(V,0);

  for(int u=0; u<V; u++){
    for(int v : adj[u]){
      in_degree[v]++;
    }
  }

  queue<int> q;

  for(int i=0; i<V; i++){
    if(in_degree[i] == 0){
      q.push(i);
    }
  }

  vector<int> topo_order;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    topo_order.push_back(u);

    for(int v : adj[u]){
      if(--in_degree[v] == 0) q.push(v);
    }
  }

  if(topo_order.size() != 0){
    court<<"Cycle detected !! Topological sorting not possible"<<endl;
    return {};
  }

  return topo_order; 
  
}


int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> adj(V);

    // Directed edges: (0 -> 1), (0 -> 2), (1 -> 3), (2 -> 3), (3 -> 4), (4 -> 5)
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3};
    adj[3] = {4};
    adj[4] = {5};

    vector<int> result = topologicalSort(V, adj);

    if (!result.empty()) {
        cout << "Topological Sort: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}





