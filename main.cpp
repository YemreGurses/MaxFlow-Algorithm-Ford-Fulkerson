#include"maxflow.h"


void read_input(int**& graph,int& node_count,std::vector<int>& sources,std::vector<int>& sinks);

int main(){
	int **graph,node_count;
	std::vector<int> sources,sinks;
	read_input(graph,node_count,sources,sinks);
	std::cout << max_flow(graph,node_count,sources,sinks) << std::endl;
	return 0;
}

void read_input(int**& graph,int& node_count,std::vector<int>& sources,std::vector<int>& sinks){
	int edge_count,sources_count,sinks_count;
	std::cin >> node_count;
	graph = new int*[node_count];
	for(int i = 0; i < node_count;i++)
		graph[i] = new int[node_count]();
	std::cin >> edge_count;
	for(int i = 0; i < edge_count;i++){
		int start,end,capacity;
		std::cin >> start >> end >> capacity;
		graph[start][end] = capacity;
	}
	std::cin >> sources_count;
	for(int i = 0; i < sources_count;i++){
		int source;
		std::cin >> source;
		sources.push_back(source);
	}
	std::cin >> sinks_count;
	for(int i = 0; i < sinks_count;i++){
		int sink;
		std::cin >> sink;
		sinks.push_back(sink);
	}
}
