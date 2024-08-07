//Dijkstra's Algorithm
#include <bits/stdc++.h>
using namespace std;

#define V 9
#define source 0

int minDistance(int distance[], bool sptSet[]){
    // Initialize the min value and index
    int min = INT_MAX, min_index;

    // For from 0 to the number of vertices of the graph
    for(int v = 0; v < 9; ++v)
        // If it was not setted first and the distance is less than the min
        if(sptSet[v] == false && distance[v] <= min)
            // Update the min value
           min = distance[v], min_index = v;

    // Return the index of the min value
    return min_index;
}

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijktras(int graph[V][V], int src){

    int distance[V]; // The output array. distance[i] will hold the shortest distance from src to i
    bool sptSet[V];

    // Initialize every node with infinite distance and false
    for(int i = 0; i < V; ++i)
        distance[i] = INT_MAX, sptSet[i] = false;

    distance[src] = source;

    for(int count = 0; count < V; ++count){
        int u = minDistance(distance, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!sptSet[v] && graph[u][v]
                            && distance[u] != INT_MAX
                            && distance[u] + graph[u][v] < distance[v])
                            distance[v] = distance[u] + graph[u][v];

        }
    }

    printSolution(distance);
}


int main(){
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    // Function call
    dijktras(graph, 0);
    return 0;
}
