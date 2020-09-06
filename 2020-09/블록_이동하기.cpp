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

bool checkScope(vector<vector<int>> board, int N, int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < N) {
		if (board[y][x] == 0) return true;
	}
	return false;
}

int solution(vector<vector<int>> board) {
	int N = board.size();
	int INF = 100000000;
	vector<vector<vector<int> > > dist;
	dist.resize(N);
	for (int i = 0; i < N; i++) {
		dist[i].resize(N);
		for (int j = 0; j < N; j++) {
			dist[i][j].assign(4, INF);
		}
	}
	dist[0][0][0] = 0;

	priority_queue < pair<int, pair<pair<int, int>, int> > > pq;
	pq.push(make_pair(0, make_pair(make_pair(0, 0), 1)));
	while (pq.empty() == false) {
		int cost = -pq.top().first;
		int y = pq.top().second.first.first;
		int x = pq.top().second.first.second;
		int dir = pq.top().second.second;
		pq.pop();

		if (dist[y][x][dir] < cost) continue;

		int nextDist = cost + 1;

		int my[4] = { -1, 0, 1, 0 };
		int mx[4] = { 0, 1, 0, -1 };
		for (int i = 0; i < 4; i++) {
			int ny1 = y + my[i];
			int nx1 = x + mx[i];
			int ny2 = ny1 + my[dir];
			int nx2 = nx1 + mx[dir];
			if (checkScope(board, N, ny1, nx1) &&
				checkScope(board, N, ny2, nx2)) {
				if (dist[ny1][nx1][dir] > nextDist) {
					dist[ny1][nx1][dir] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(make_pair(ny1, nx1), dir)));
				}
			}
		}

		int ny, nx;
		int y1 = y, x1 = x;
		int y2 = y + my[dir], x2 = x + mx[dir];
		if (dir == 1) {
			if (checkScope(board, N, y1 - 1, x1) &&
				checkScope(board, N, y1 - 1, x2)) {
				// 1
				ny = y1 - 1, nx = x1;
				if (dist[ny][nx][2] > nextDist) {
					dist[ny][nx][2] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(make_pair(ny, nx), 2)));
				}
				// 2
				ny = y1 - 1, nx = x2;
				if (dist[ny][nx][2] > nextDist) {
					dist[ny][nx][2] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(make_pair(ny, nx), 2)));
				}
			}
			if (checkScope(board, N, y1 + 1, x1) &&
				checkScope(board, N, y1 + 1, x2)) {
				// 3
				if (dist[y1][x1][2] > nextDist) {
					dist[y1][x1][2] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(make_pair(y1, x1), 2)));
				}
				// 4
				if (dist[y2][x2][2] > nextDist) {
					dist[y2][x2][2] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(make_pair(y2, x2), 2)));
				}
			}
		}
		else if (dir == 2) {
			if (checkScope(board, N, y1, x1 - 1) &&
				checkScope(board, N, y2, x1 - 1)) {
				// 1
				ny = y1, nx = x1 - 1;
				if (dist[ny][nx][1] > nextDist) {
					dist[ny][nx][1] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(make_pair(ny, nx), 1)));
				}
				// 2
				ny = y2, nx = x1 - 1;
				if (dist[ny][nx][1] > nextDist) {
					dist[ny][nx][1] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(make_pair(ny, nx), 1)));
				}
			}
			if (checkScope(board, N, y1, x1 + 1) &&
				checkScope(board, N, y2, x1 + 1)) {
				// 3
				if (dist[y1][x1][1] > nextDist) {
					dist[y1][x1][1] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(make_pair(y1, x1), 1)));
				}
				// 4
				if (dist[y2][x2][1] > nextDist) {
					dist[y2][x2][1] = nextDist;
					pq.push(make_pair(-nextDist, make_pair(make_pair(y2, x2), 1)));
				}
			}
		}
	}
	return min(dist[N - 1][N - 2][1], dist[N - 2][N - 1][2]);
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> A;
	int N = 30;
	A.resize(N);
	for (int i = 0; i < A.size(); i++) A[i].assign(N, 0);
	
	//A[0][3] = A[0][4] = A[1][3] = A[2][1] = A[2][3] = A[2][4] = A[3][0] = A[3][1] = A[3][4] = 1;
	cout << solution(A);
	return 0;
}