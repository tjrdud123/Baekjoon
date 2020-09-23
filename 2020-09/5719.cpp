#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
int N, M;
int adj[500][500];
vector<int> parent[500];
int dijk(int s, int d) {
	int INF = 1000000000;
	vector<int> dist(N, INF);
	for (int i = 0; i < N; i++) parent[i].clear();
	dist[s] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));

	while (pq.empty() == false) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int there = 0; there < N; there++) {
			if (adj[here][there] == 0) continue;
			int nextDist = cost + adj[here][there];

			if (dist[there] > nextDist) {
				parent[there].clear();
				parent[there].push_back(here);
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
			else if (dist[there] == nextDist) {
				parent[there].push_back(here);
			}
		}
	}
	return dist[d];
}
void dfs(int d) {
	for (int i = 0; i < parent[d].size(); i++) {
		adj[parent[d][i]][d] = 0;
		dfs(parent[d][i]);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int s, d;
	while (true) {
		cin >> N >> M;
		if (N == 0) break;
		memset(adj, 0, sizeof(adj));
		cin >> s >> d;
		int u, v, c;
		for (int i = 0; i < M; i++) {
			cin >> u >> v >> c;
			adj[u][v] = c;
		}
		int minCost = dijk(s, d);
		dfs(d);
		int cost = dijk(s, d);
		if (cost == 1000000000) cout << -1 << "\n";
		else cout << cost << "\n";
	}
	return 0;
}