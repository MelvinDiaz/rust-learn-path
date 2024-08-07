#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    // Create a priority queue to store the vertices and the weight
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int>>> pq;
    // Array to store the distance from each node to the source
    vector<int> dist(V);

    // Initialize the distance array with infinite distance
    for(int i = 0; i < V; i++){
      dist[i] = INT_MAX;
    }

    // Set the distance from the source to itself as 0
    dist[S] = 0;
    pq.push({0,S});

    // Loop until the priority queue is empty
    while(!pq.empty()){
      
      // Obtain the current top element of the priority queue (heap)
      int dis = pq.top().first;
      int node = pq.top().second;

      // Remove the top element from the priority queue because we already have it
      pq.pop();

      // Loop through the adjacency list of the current node. 
      for(auto it: adj[node]){

        // Get the weight of the edge and the adjacent node
        int edgeWeight = it[1];
        int adjNode = it[0];

        // If the distance from the source to the adjacent node is greater than the distance from the source to the current node plus the weight of the edge
        if(dis + edgeWeight < dist[adjNode]){
          // Update the distance from the source to the adjacent node
          dist[adjNode] = dis + edgeWeight;
          // Push the new distance and the adjacent node to the priority queue
          pq.push({dist[adjNode], adjNode});
        }
      }
    }
    return dist;

}

int main () {
    int V, E;
    // V = number of vertices, E = number of edges in the graph
    cin >> V >> E;
    int u, v, w;
    vector<vector<int>> adj[V];

    // For in the number of edges of the graph.
    // Read the vertices and the weight between them
    for(int i = 0; i < E; i++){
      cin >> u >> v >> w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    // S = source node
    int S;
    cin >> S;

    // Call the function dijkstra
    vector<int> res = dijkstra(V, adj, S);
    cout << "Shortest distance from source " << S << " to all other nodes is: " << endl;
    for(int i = 0; i < V; i++){
      cout << res[i] << " ";
    }

    return 0;
}
