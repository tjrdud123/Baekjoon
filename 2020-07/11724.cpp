#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int N, M;
bool adj[1001][1001];
bool visited[1001];
void dfs(int node) {
	visited[node] = 1;
	for (int i = 1; i <= N; i++) {
		if (adj[node][i] && visited[i] == false) {
			dfs(i);
		}
	}
}
int dfsAll() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			dfs(i);
			ret++;
		}
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	memset(adj, 0, sizeof(adj));
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	cout << dfsAll();
	return 0;
}