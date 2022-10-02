#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1e3;
vector<int> graph[N + 1];
bool visited[N + 1];
bool isLoopExists = false;

//O(V + E)
bool cycle_detection(int vertex, int parent){
	//operations to perform after entering a vertex

	visited[vertex] = true;
	for(auto &child : graph[vertex]){
		// operations to perform before entering in a child
		if(visited[child] == true && child == parent)	continue;
		if(visited[child])	return true;
		
		//operations to perform after exiting a child;
		isLoopExists |= cycle_detection(child, vertex);

	}
	//operations to perform after before exiting a vertex;
	return isLoopExists;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i <m; ++i){
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].pb(v2);
		graph[v2].pb(v1);
	}
	for(int i =1; i <=n; ++i){
		for(auto &child : graph[i])
			cout << child << " ";	
		cout << "\n";
	}
	bool ans = false;
	for(int i = 1; i<=n; ++i){
		if(!visited[i]){
			visited[i] = true;
			ans |= cycle_detection(i, 0);
		}
	}
	
	cout << ans;
	return 0;
}

