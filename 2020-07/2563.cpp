#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
vector<vector<bool> > A;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(100);
	for (int i = 0; i < 100; i++)
		A[i].assign(100, 0);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		for (int a = y; a < y + 10; a++) {
			for (int b = x; b < x + 10; b++) {
				A[a][b] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (A[i][j])
				ans++;
		}
	}
	cout << ans;
	return 0;
}