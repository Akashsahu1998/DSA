#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v){
	for(int itr = 0; itr < v; itr++){
		cout << itr << " => ";
		for(auto a: adj[itr]){
			cout << a << " ";	
		}
		cout << endl;
	}
}

int main(){
	int v = 4;
	vector<int> adj[4];
	
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);

	printGraph(adj, v);
}
