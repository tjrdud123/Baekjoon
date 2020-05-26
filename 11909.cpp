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
int N;
int INF = 987654321;
int A[2300 * 2300];
vector<int> dijkstra(int src) {
	vector<int> dist(N * N + 1, INF);
	dist[src] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost)
			continue;

		int there;
		int nextDist;

		if (here == N * N) {

		}
		else if (here % N == 0) {
			there = here + N;
			if (A[here] > A[there]) {
				nextDist = cost;
			}
			else {
				nextDist = cost + A[there] - A[here] + 1;
			}

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
		else if (here > N * (N - 1)) {
			there = here + 1;
			if (A[here] > A[there]) {
				nextDist = cost;
			}
			else {
				nextDist = cost + A[there] - A[here] + 1;
			}

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
		else {
			there = here + N;
			if (A[here] > A[there]) {
				nextDist = cost;
			}
			else {
				nextDist = cost + A[there] - A[here] + 1;
			}

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}

			there = here + 1;
			if (A[here] > A[there]) {
				nextDist = cost;
			}
			else {
				nextDist = cost + A[there] - A[here] + 1;
			}

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
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[(i - 1) * N + j];
		}
	}
	vector<int> dist = dijkstra(1);
	cout << dist[N * N] << endl;
	return 0;
}