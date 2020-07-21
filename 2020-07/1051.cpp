#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int maxV = 1;
int N, M;
int A[50][50];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			A[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; ; k++) {
				if (i + k >= N || j + k >= M)
					break;
				if (A[i][j] == A[i][j + k] && A[i][j + k] == A[i + k][j + k] && A[i + k][j + k] == A[i + k][j]) {
					maxV = max(maxV, (k + 1) * (k + 1));
				}
			}
		}
	}
	cout << maxV;
	return 0;
}