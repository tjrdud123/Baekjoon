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
int N;
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };
int maxA = 0;
vector<vector<int> > A;

void sol(int idx) {
	
	if (idx == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maxA = max(maxA, A[i][j]);
			}
		}
		return;
	}
	vector<vector<int> > temp = A;
	bool isJoined[20][20];
	int dir;
	dir = 0; // 12
	memset(isJoined, 0, sizeof(isJoined));
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] != 0) {
				int y = i;
				int x = j;
				while (1) {
					y = y + my[dir];
					x = x + mx[dir];
					if (y == 0 || A[y][x] != 0) break;
				}
				if (A[y][x] == A[i][j] && isJoined[y][x] == false) {
					isJoined[y][x] = true;
					A[y][x] *= 2;
					A[i][j] = 0;
				}
				else {
					if (y == 0 && A[y][x] == 0) {
						A[y][x] = A[i][j];
						A[i][j] = 0;
					}
					else {
						A[y + 1][x] = A[i][j];
						if (y + 1 != i) A[i][j] = 0;
					}
					
				}
			}
		}
	}
	
	sol(idx + 1);
	A = temp;
	dir = 1; // 3
	memset(isJoined, 0, sizeof(isJoined));
	for (int j = N - 2; j >= 0; j--) {
		for (int i = 0; i < N; i++) {
			if (A[i][j] != 0) {
				int y = i;
				int x = j;
				while (1) {
					y = y + my[dir];
					x = x + mx[dir];
					if (x == N - 1 || A[y][x] != 0) break;
				}
				if (A[y][x] == A[i][j] && isJoined[y][x] == false) {
					isJoined[y][x] = true;
					A[y][x] *= 2;
					A[i][j] = 0;
				}
				else {
					if (x == N - 1 && A[y][x] == 0) {
						A[y][x] = A[i][j];
						A[i][j] = 0;
					}
					else {
						A[y][x - 1] = A[i][j];
						if (x - 1 != j) A[i][j] = 0;
					}
				}
			}
		}
	}

	sol(idx + 1);
	A = temp;
	dir = 2; // 6
	memset(isJoined, 0, sizeof(isJoined));
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] != 0) {
				int y = i;
				int x = j;
				while (1) {
					y = y + my[dir];
					x = x + mx[dir];
					if (y == N - 1 || A[y][x] != 0) break;
				}
				if (A[y][x] == A[i][j] && isJoined[y][x] == false) {
					isJoined[y][x] = true;
					A[y][x] *= 2;
					A[i][j] = 0;
				}
				else {
					if (y == N - 1 && A[y][x] == 0) {
						A[y][x] = A[i][j];
						A[i][j] = 0;
					}
					else {
						A[y - 1][x] = A[i][j];
						if (y - 1 != i) A[i][j] = 0;
					}
				}
			}
		}
	}
	
	sol(idx + 1);
	A = temp;
	dir = 3; // 9
	memset(isJoined, 0, sizeof(isJoined));
	for (int j = 1; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (A[i][j] != 0) {
				int y = i;
				int x = j;
				while (1) {
					y = y + my[dir];
					x = x + mx[dir];
					if (x == 0 || A[y][x] != 0) break;
				}
				if (A[y][x] == A[i][j] && isJoined[y][x] == false) {
					isJoined[y][x] = true;
					A[y][x] *= 2;
					A[i][j] = 0;
				}
				else {
					if (x == 0 && A[y][x] == 0) {
						A[y][x] = A[i][j];
						A[i][j] = 0;
					}
					else {
						A[y][x + 1] = A[i][j];
						if (x + 1 != j) A[i][j] = 0;
					}
				}
				
			}
		}
	}

	sol(idx + 1);
	A = temp;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(N);
	
	for (int i = 0; i < N; i++) {
		A[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	sol(0);
	cout << maxA;
	return 0;
}