#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1e3;
vector<int> graph[N + 1];
bool visited[N + 1];
vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){
	//operations to perform after entering a vertex
	current_cc.pb(vertex);
	visited[vertex] = true;
	for(auto &child : graph[vertex]){
		// operations to perform before entering in a child
		if(visited[child] == true)	continue;
		dfs(child);
		//operations to perform after exiting a child;

	}
	//operations to perform after before exiting a vertex;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i <m; ++i){
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].pb(v2);
		graph[v2].pb(v1);
		//this is for grp
	}
	for(int i =1; i <=n; ++i){
		for(auto &child : graph[i])
			cout << child << " ";	
		cout << "\n";
	}
	int count = 0;
	for(int i = 1; i <=n; ++i){
		if(visited[i] == false){
			visited[i] = true;
			current_cc.clear();
			dfs(i);	
			cc.pb(current_cc);
			count++;
		}
	}
	for(auto &components : cc){
		for(auto &vertex : components){
			cout << vertex << " ";
		}
		cout << endl;
	}
	cout << "\nTotal connected components are : " << cc.size() << endl;

	return 0;
}















