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
vector<vector<int>> lotate(vector<vector<int>> key) {
	// 시계 방향
	int N = key.size();
	vector<vector<int>> ret;
	ret.resize(N);
	int k = N - 1;
	for (int i = 0; i < N; i++) ret[i].resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret[j][k] = key[i][j];
		}
		k--;
	}
	return ret;
}
bool isOpen(vector<vector<int>> A, int N, int offset) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[offset + i][offset + j] != 1) return false;
		}
	}
	return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int N = lock.size(), M = key.size();
	int K = N + 2 * M - 2;
	int offset = M - 1;
	vector<vector<int>> A, B;
	A.resize(K);
	for (int i = 0; i < K; i++) A[i].assign(K, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[offset + i][offset + j] = lock[i][j];
		}
	}
	B = A;
	
	for (int k = 0; k < 4; k++) {
		for (int r = 0; r <= K - M; r++) {
			for (int c = 0; c <= K - M; c++) {
				for (int i = 0; i < M; i++) {
					for (int j = 0; j < M; j++) {
						A[r + i][c + j] += key[i][j];
					}
				}
				
				if (isOpen(A, N, offset)) return true;
				A = B;
			}
		}

		key = lotate(key);
	}
	return false;
}
