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
int N, M;
char A[50][50];
char chessW[8][8];
char chessB[8][8];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0) {
					chessW[i][j] = 'W';
					chessB[i][j] = 'B';
				}
				else {
					chessW[i][j] = 'B';
					chessB[i][j] = 'W';
				}
			}
		}
		else {
			for (int j = 7; j >= 0; j--) {
				if (j % 2 == 0) {
					chessW[i][j] = 'B';
					chessB[i][j] = 'W';
				}
				else {
					chessW[i][j] = 'W';
					chessB[i][j] = 'B';
				}
			}
		}
	}
	
	int minV = 987654321;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int cnt = 0;
			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					if (chessW[a][b] != A[a + i][b + j])
						cnt++;
				}
			}
			minV = min(minV, cnt);
			cnt = 0;
			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					if (chessB[a][b] != A[a + i][b + j])
						cnt++;
				}
			}
			minV = min(minV, cnt);
		}
	}
	cout << minV;
	return 0;
}