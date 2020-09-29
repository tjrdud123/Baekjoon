#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
vector<pair<int, int> > adj[1001];
vector<int> dijkstra(int src, int dest) {
	const int INF = 1000000000;
	vector<int> dist(N + 1, INF);
	vector<int> from(N + 1);
	from[src] = -1;
	dist[src] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while (pq.empty() == false) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] >= nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
				from[there] = here;
			}
		}
	}
	from[0] = dist[dest];
	return from;
}
vector<int> path;
void getPath(vector<int> from, int dest) {
	if (from[dest] == -1) {
		path.push_back(dest);
		return;
	}
	getPath(from, from[dest]);
	path.push_back(dest);
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	int u, v;
	cin >> u >> v;
	vector<int> from = dijkstra(u, v);
	cout << from[0] << "\n";

	getPath(from, v);
	cout << path.size() << "\n";
	for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
	return 0;
}