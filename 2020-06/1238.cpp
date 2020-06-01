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
int N, M, X;
int INF = 987654321;
int adj[1001][1001];
int dist[1001][1001];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X;
	memset(adj, 0, sizeof(adj));
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				dist[i][j] = 0;
			else if (adj[i][j])
				dist[i][j] = adj[i][j];
			else
				dist[i][j] = INF;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int cost[1001];
	int maxV = -1;
	for (int i = 1; i <= N; i++) {
		cost[i] = dist[i][X] + dist[X][i];
		maxV = max(maxV, cost[i]);
	}
	cout << maxV << endl;
	return 0;
}