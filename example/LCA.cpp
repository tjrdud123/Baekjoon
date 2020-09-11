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
int N, M;
vector<int> depth;
vector<vector<int> > anc;
vector<bool> visited;
vector<vector<int> > edges;
void dfs(int n, int d) {
	visited[n] = true;
	depth[n] = d;

	for (int i = 0; i < edges[n].size(); i++) {
		if (visited[edges[n][i]]) continue;
		anc[edges[n][i]][0] = n;
		dfs(edges[n][i], d + 1);
	}
}
int LCA(int a, int b) {

	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) swap(a, b);

		for (int i = 20; i >= 0; i--) {
			if (depth[b] - depth[a] >= (1 << i)) {
				b = anc[b][i];
			}
		}
	}
	if (a == b) return a;
	if (a != b) {
		for (int i = 20; i >= 0; i--) {
			if (anc[a][i] != anc[b][i]) {
				a = anc[a][i];
				b = anc[b][i];
			}
		}
	}
	return anc[a][0];
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	depth.resize(N + 1);
	anc.resize(N + 1);
	visited.assign(N + 1, false);
	edges.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		anc[i].resize(21);
	}
	for (int i = 0; i < N - 1; i++) {

		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	anc[1][0] = 0;
	dfs(1, 0);

	for (int n = 1; n <= 20; n++) {
		for (int x = 1; x <= N; x++) {
			anc[x][n] = anc[anc[x][n - 1]][n - 1];
		}
	}


	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
	return 0;
}