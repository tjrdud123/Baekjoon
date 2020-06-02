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
int cnt[2] = { 0, 0 };
vector<vector<int> > A;
void f(int r, int c, int n) {
	if (n == 1) {
		cnt[A[r][c]]++;
		return;
	}
	int color = A[r][c];
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[r + i][c + j] != color) {
				flag = 1;
			}
		}
	}
	if (flag) {
		f(r, c, n / 2);
		f(r, c + n / 2, n / 2);
		f(r + n / 2, c, n / 2);
		f(r + n / 2, c + n / 2, n / 2);
	}
	else {
		cnt[color]++;
		return;
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
		A[i].resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	f(0, 0, N);
	cout << cnt[0] << "\n" << cnt[1];

	return 0;
}