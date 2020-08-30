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
int N, M, H;
vector<vector<int> > A;
int ans = 999999;
bool check() {
	bool flag = 1;
	for (int i = 0; i < N; i++) {
		int val = i;
		for (int h = 0; h < H; h++) {
			if (A[h][val] == 1) val++;
			else if (A[h][val] == 2) val--;
		}
		if (i != val) {
			flag = 0;
			break;
		}
	}
	return flag;
}
void sol(int cnt, int CNT, int hh, int jj) {
	if (cnt == CNT) {
		if(check()) ans = min(ans, cnt);
		return;
	}
	for (int j = jj; j < N - 1; j++) {
		int h;
		if (j == jj) h = hh;
		else h = 0;
		for (; h < H; h++) {
			if (A[h][j] == 0 && A[h][j + 1] == 0) {
				A[h][j] = 1;
				A[h][j + 1] = 2;
				sol(cnt + 1, CNT, h, j);
				A[h][j] = A[h][j + 1] = 0;
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> H;
	A.resize(H);
	for (int i = 0; i < H; i++) A[i].assign(N, 0);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		A[a - 1][b - 1] = 1;
		A[a - 1][b] = 2;
	}
	
	sol(0, 0, 0, 0);
	sol(0, 1, 0, 0);
	sol(0, 2, 0, 0);
	sol(0, 3, 0, 0);
	
	if (ans > 3) cout << -1;
	else cout << ans;
	return 0;
}