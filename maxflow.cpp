#include"maxflow.h"

using namespace std; 

bool bfs(int** rGraph, int s, int t, int parent[], int n) 
{ 
	bool visited[n]; 
	for(int k=0; k<n; k++){
	    visited[k] = 0;
	}

	queue <int> q; 
	q.push(s); 
	visited[s] = true; 
	parent[s] = -1; 

	//BFS Loop 
	while (!q.empty()) 
	{ 
		int u = q.front(); 
		q.pop(); 

		for (int v=0; v<n; v++) 
		{ 
			if (visited[v]==false && rGraph[u][v] > 0) 
			{ 
				q.push(v); 
				parent[v] = u; 
				visited[v] = true; 
			} 
		} 
	} 

	return (visited[t] == true); 
} 


int max_flow(int** graph,int  n, std::vector<int> sources, std::vector<int> sinks){
	int u, v; 
   
    int** rGraph;
    rGraph = new int*[n];
	for(int i = 0; i < n;i++)
		rGraph[i] = new int[n]();
    

	for (u = 0; u < n; u++) 
		for (v = 0; v < n; v++) 
			rGraph[u][v] = graph[u][v]; 

	int parent[n];

	int max_flow = 0;
    for(int a=0; a<sources.size(); a++){
        for(int b=0; b<sinks.size(); b++){
        	while (bfs(rGraph, sources[a], sinks[b], parent, n)) 
            { 
        		int path_flow = INT_MAX; 
        		for (v=sinks[b]; v!=sources[a]; v=parent[v]) 
        		{ 
        			u = parent[v]; 
        			path_flow = min(path_flow, rGraph[u][v]); 
        		} 
        
        		for (v=sinks[b]; v != sources[a]; v=parent[v]) 
        		{ 
        			u = parent[v]; 
        			rGraph[u][v] -= path_flow; 
        			rGraph[v][u] += path_flow; 
        		} 

        		max_flow += path_flow; 
	        } 
        }
    }

	return max_flow;         
} 