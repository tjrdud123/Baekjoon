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
int N;
int INF = 987654312;
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };
vector<vector<int> > A;
int sol(int y, int x) {
	vector<vector<int> > dist;
	dist.resize(N);
	for (int i = 0; i < N; i++) dist[i].assign(N, INF);
	dist[y][x] = A[y][x];

	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push(make_pair(-dist[y][x], make_pair(y, x)));

	while (!pq.empty()) {
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[y][x] < cost) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + my[i];
			int nx = x + mx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				int nextDist = cost + A[ny][nx];

				if (dist[ny][nx] > nextDist) {
					dist[ny][nx] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(ny, nx)));
				}
			}
		}
	}

	return dist[N - 1][N - 1];
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n = 1;
	while (true) {
		cin >> N;
		if (N == 0) break;
		A.resize(N);
		for (int i = 0; i < N; i++) {
			A[i].resize(N);
			for (int j = 0; j < N; j++) cin >> A[i][j];
		}
		cout << "Problem " << n++ << ": " << sol(0, 0) << "\n";
	}


	return 0;
}