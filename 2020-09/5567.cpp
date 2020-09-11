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
vector<vector<int> > adj;
int bfs(int src, int n) {
	vector<int> dist(n + 1, -1);
	dist[src] = 0;

	queue<int> q;
	q.push(src);

	int ret = 0;
	while (q.empty() == false) {
		int here = q.front();
		q.pop();

		int dis = dist[here];
		if (0 < dis && dis <= 2) ret++;

		for (int i = 1; i <= n; i++) {
			if (adj[here][i]) {
				if (dist[i] == -1) {
					dist[i] = dis + 1;
					q.push(i);
				}
			}
		}
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	adj.resize(N + 1);
	for (int i = 0; i < N + 1; i++) adj[i].assign(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	cout << bfs(1, N);
	return 0;
}