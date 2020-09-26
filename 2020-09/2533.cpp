#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N;
vector<int> children[1000001];
vector<int> adj[1000001];
vector<bool> visited;
int cache[1000001][2];
void dfs(int src) {
	visited[src] = true;

	for (int i = 0; i < adj[src].size(); i++) {
		int there = adj[src][i];
		if (visited[there] == false) {
			children[src].push_back(there);
			dfs(there);
		}
	}
}
int getF(int node, int picked) {
	int &ret = cache[node][picked];
	if (ret != -1) return ret;

	int sum = 0;
	if (picked) {
		sum++;
		for (int i = 0; i < children[node].size(); i++) {
			int child = children[node][i];
			sum += min(getF(child, 0), getF(child, 1));
		}
	}
	else {
		for (int i = 0; i < children[node].size(); i++) {
			int child = children[node][i];
			sum += getF(child, 1);
		}
	}

	return ret = sum;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	visited.assign(1000001, false);
	dfs(1);

	memset(cache, -1, sizeof(cache));
	cout << min(getF(1, 0), getF(1, 1));

	return 0;
}