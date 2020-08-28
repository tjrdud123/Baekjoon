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
int N, M;
int INF = 987654321;
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };
vector<vector<int> > A;
int sol(int y, int x) {
	vector<vector<int> > dist;
	dist.resize(N);
	for (int i = 0; i < N; i++) dist[i].assign(M, INF);
	dist[y][x] = 0;

	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push(make_pair(0, make_pair(y, x)));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		if (dist[y][x] < cost) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + my[i];
			int nx = x + mx[i];
			
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				int nextDist = cost + A[ny][nx];
				if (dist[ny][nx] > nextDist) {
					dist[ny][nx] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(ny, nx)));
				}
			}
		}
	}
	return dist[N - 1][M - 1];
}
vector<vector<int> > adj;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	A.resize(N);

	for (int i = 0; i < N; i++) {
		A[i].resize(M);
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			A[i][j] = str[j] - '0';
		}
	}

	cout << sol(0, 0);
	return 0;
}