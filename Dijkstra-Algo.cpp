/*

Purpose: Used to find the shortest path from a src node to all other nodes in a weighted graph(works with non-negative weights).

How Dijkstra’s Algorithm Works:-

1. Create distance array(dist[]) and initially all distances are INT_MAX, dist[src] = 0; 
2. Use a min-heap (priority queue) to keep track of the node with the smallest current distance.
3. While the priority queue is not empty do the following:  
          3.1-> Take the node with the smallest distance.
          3.2-> For each neighbor of this node:
                3.2.1-> If the current path is shorter then dist[] array.
                3.2.2-> Push the updated distance and node into the priority queue.
4. When the queue becomes empty -> Return dist[] array which contains the shortest path from src to all the other nodes.

*/

#include<bits/stdc++.h>
using namespace std;



vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src){
  vector<int> dist(V, INT_MAX);
  priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
  dist[src]=0;
  pq.push({0,src});

  while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;

        if(d>dist[node]) continue;

        for(auto &edge : adj[node]){
          int neighbor = edge.first;
          int weight = edge.second;

          if(dist[node] + weight < dist[neighbor]){
            dist[neighbor] = dist[node] + weight;
            pq.push({dist[neighbor], neighbor});
          }          
        }
      }  
  
  return dist;

}


int main() {
    int V = 9; 
    vector<vector<pii>> adj(V);
    adj[0].push_back({1, 4});
    adj[0].push_back({7, 8});
    adj[1].push_back({0, 4});
    adj[1].push_back({2, 8});
    adj[2].push_back({1, 8});
    adj[2].push_back({3, 7});
    adj[2].push_back({5, 4});
    adj[3].push_back({2, 7});
    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});
    adj[4].push_back({5, 10});
    adj[5].push_back({2, 4});
    adj[5].push_back({4, 10});
    adj[5].push_back({6, 2});
    adj[6].push_back({5, 2});
    adj[6].push_back({7, 1});
    adj[7].push_back({0, 8});
    adj[7].push_back({6, 1});
    adj[7].push_back({8, 7});
    adj[8].push_back({7, 7});

    int src = 0;
    vector<int> distances = dijkstra(V, adj, src);

    cout << "Shortest distances from node " << src << "\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << distances[i] << "\n";
    }

    return 0;
}
