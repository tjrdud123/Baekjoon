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
using namespace std;
int T;
vector<vector<pair<int, int> >> adj;
vector<int> dijkstra(int src, int n) {
	int INF = 987654322;
	vector<int> dist(n + 1, INF);

	dist[src] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while (pq.empty() == false) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].second;
			int nextDist = cost + adj[here][i].first;

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
	cin >> T;
	while (T--) {
		int n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;
		adj.resize(n + 1);
		
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			if ((a == g && b == h) || (a == h && b == g)) {
				adj[a].push_back(make_pair(2 * d - 1, b));
				adj[b].push_back(make_pair(2 * d - 1, a));
			}
			else {
				adj[a].push_back(make_pair(2 * d, b));
				adj[b].push_back(make_pair(2 * d, a));
			}
		}
		vector<int> dist = dijkstra(s, n);
		vector<int> ans;
		//for (int i = 1; i < dist.size(); i++) cout << dist[i] << "  ";
		//cout << "\n";
		for (int i = 0; i < t; i++) {
			int temp; cin >> temp;
			if (dist[temp] % 2 == 1) ans.push_back(temp);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << "\n";
		adj.clear();
	}
	return 0;
}