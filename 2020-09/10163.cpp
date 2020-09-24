#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N;
vector<vector<int> > A;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(200);
	for (int i = 0; i < 200; i++) {
		A[i].assign(200, -1);
	}
	for (int q = 0; q < N; q++) {
		int y, x, h, w;
		cin >> x >> y >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				A[y + i][x + j] = q;
			}
		}
	}
	vector<int> cnt(101, 0);
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if(A[i][j] != -1) cnt[A[i][j]]++;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << cnt[i] << "\n";
	}
	return 0;
}