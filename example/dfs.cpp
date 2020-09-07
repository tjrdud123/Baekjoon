#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <ctype.h>
using namespace std;
vector<vector<int> > adj;
vector<bool> visited;
void dfs(int src, int N) {
	if (visited[src]) return;

	visited[src] = true;
	for (int i = 0; i < N; i++) {
		if (adj[src][i]) dfs(i, N);
	}
}
void dfsAll(int N) {
	adj.resize(N);
	for (int i = 0; i < N; i++) adj[i].resize(N);
	visited.assign(N, false);
	for (int i = 0; i < N; i++) {
		if (visited[i] == false) dfs(i, N);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	return 0;
}