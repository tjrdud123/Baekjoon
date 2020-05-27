#include <math.h>
#include <stdio.h>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <utility>
using namespace std;
int N, E, A, B;
int INF = 487654321;
vector<pair<int, int> > adj[801];
vector<int> dijkstra(int src) {
	vector<int> dist(N + 1, INF);
	dist[src] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost)
			continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	cin >> A >> B;
	vector<int> dist = dijkstra(1);
	int d1 = dist[A];
	int d2 = dist[B];
	dist = dijkstra(A);
	d1 += dist[B];
	d2 += dist[N];
	dist = dijkstra(B);
	d2 += dist[A];
	d1 += dist[N];
	if (d1 >= INF && d2 >= INF) {
		cout << -1;
	}
	else
		cout << min(d1, d2);
	return 0;
}