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
using namespace std;
int N, M, ans;
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };
vector<vector<int> > A, B;
vector<pair<int, pair<int, int> > > cctvs;
void copyArr(vector<vector<int> >& A, vector<vector<int> >& B) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = B[i][j];
		}
	}
}
void sol(int idx) {
	vector<vector<int> > C;
	if (idx == cctvs.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (A[i][j] == 0) cnt++;
				
			}
		}
		
		ans = min(ans, cnt);
		return;
	}
	int Y, X, y, x;
	Y = cctvs[idx].second.first;
	X = cctvs[idx].second.second;
	C = A;
	if (cctvs[idx].first == 1) {
		
		for (int i = 0; i < 4; i++) {
			
			y = Y;
			x = X;
			while (true) {
				int ny = y + my[i];
				int nx = x + mx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
				if (A[ny][nx] == 6) break;
				y = ny;
				x = nx;
				if (A[y][x] == 0) A[y][x] = 8;
			}
			sol(idx + 1);
			A = C;
		}
	}
	else if (cctvs[idx].first == 2) {
		
		y = Y;
		x = X;
		while (true) {
			int ny = y + my[0];
			int nx = x + mx[0];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
			if (A[ny][nx] == 6) break;
			y = ny;
			x = nx;
			if (A[y][x] == 0) A[y][x] = 8;
		}
		y = Y;
		x = X;
		while (true) {
			int ny = y + my[2];
			int nx = x + mx[2];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
			if (A[ny][nx] == 6) break;
			y = ny;
			x = nx;
			if (A[y][x] == 0) A[y][x] = 8;
		}
		sol(idx + 1);
		A = C;
		y = Y;
		x = X;
		while (true) {
			int ny = y + my[1];
			int nx = x + mx[1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
			if (A[ny][nx] == 6) break;
			y = ny;
			x = nx;
			if (A[y][x] == 0) A[y][x] = 8;
		}
		y = Y;
		x = X;
		while (true) {
			int ny = y + my[3];
			int nx = x + mx[3];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
			if (A[ny][nx] == 6) break;
			y = ny;
			x = nx;
			if (A[y][x] == 0) A[y][x] = 8;
		}
		sol(idx + 1);
		A = C;
	}
	else if (cctvs[idx].first == 3) {
		for (int i = 0; i < 4; i++) {
			
			y = Y;
			x = X;
			while (true) {
				int ny = y + my[i];
				int nx = x + mx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
				if (A[ny][nx] == 6) break;
				y = ny;
				x = nx;
				if (A[y][x] == 0) A[y][x] = 8;
			}
			y = Y;
			x = X;
			while (true) {
				int ny = y + my[(i + 1)%4];
				int nx = x + mx[(i + 1)%4];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
				if (A[ny][nx] == 6) break;
				y = ny;
				x = nx;
				if (A[y][x] == 0) A[y][x] = 8;
			}
			sol(idx + 1);
			A = C;
		}
	}
	else if (cctvs[idx].first == 4) {
		for (int i = 0; i < 4; i++) {
			
			y = Y;
			x = X;
			while (true) {
				int ny = y + my[i];
				int nx = x + mx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
				if (A[ny][nx] == 6) break;
				y = ny;
				x = nx;
				if (A[y][x] == 0) A[y][x] = 8;
			}
			y = Y;
			x = X;
			while (true) {
				int ny = y + my[(i + 1)%4];
				int nx = x + mx[(i + 1) % 4];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
				if (A[ny][nx] == 6) break;
				y = ny;
				x = nx;
				if (A[y][x] == 0) A[y][x] = 8;
			}
			y = Y;
			x = X;
			while (true) {
				int ny = y + my[(i + 2) % 4];
				int nx = x + mx[(i + 2) % 4];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
				if (A[ny][nx] == 6) break;
				y = ny;
				x = nx;
				if (A[y][x] == 0) A[y][x] = 8;
			}
			sol(idx + 1);
			A = C;
		}
	}
	else if (cctvs[idx].first == 5) {
		
		for (int i = 0; i < 4; i++) {
			y = Y;
			x = X;
			while (true) {
				int ny = y + my[i];
				int nx = x + mx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
				if (A[ny][nx] == 6) break;
				y = ny;
				x = nx;
				if (A[y][x] == 0) A[y][x] = 8;
			}
		}
		sol(idx + 1);
		A = C;
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	ans = N * M;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; i++) A[i].resize(M);
	for (int i = 0; i < N; i++) B[i].resize(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			if (A[i][j] != 0 && A[i][j] != 6) cctvs.push_back(make_pair(A[i][j], make_pair(i, j)));
		}
	}
	sol(0);
	cout << ans;

	return 0;
}