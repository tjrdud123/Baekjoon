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
int Y, X, M;
typedef struct shark {
	int y, x, s, dir, size;
} shark;
vector<shark> sharks;
vector<vector<shark> > A;
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };
void init() {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			A[i][j].size = -1;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Y >> X >> M;
	A.resize(Y);
	for (int i = 0; i < Y; i++) A[i].resize(X);
	sharks.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> sharks[i].y >> sharks[i].x >> sharks[i].s >> sharks[i].dir >> sharks[i].size;
		if (sharks[i].dir == 1) sharks[i].dir = 0;
		else if (sharks[i].dir == 2) sharks[i].dir = 2;
		else if (sharks[i].dir == 3) sharks[i].dir = 1;
		else if (sharks[i].dir == 4) sharks[i].dir = 3;
		sharks[i].y--;
		sharks[i].x--;


		if (sharks[i].dir == 0 || sharks[i].dir == 2) {
			int t = 2 * Y - 2;
			while (sharks[i].s >= t) sharks[i].s -= t;
		}
		else if (sharks[i].dir == 1 || sharks[i].dir == 3) {
			int t = 2 * X - 2;
			while (sharks[i].s >= t) sharks[i].s -= t;
		}
	}
	int ans = 0;
	for (int j = 0; j < X; j++) {
		
		init();
		for (int k = 0; k < sharks.size(); k++) {
			shark sh = sharks[k];
			if (A[sh.y][sh.x].size < sh.size) {
				A[sh.y][sh.x] = sh;
			}
		}
		for (int i = 0; i < Y; i++) {
			if (A[i][j].size != -1) {
				ans += A[i][j].size;
				//cout << j << " " << ans << "\n";
				A[i][j].size = -1;
				break;
			}
		}
		sharks.clear();
		
		for (int a = 0; a < Y; a++) {
			for (int b = 0; b < X; b++) {
				if (A[a][b].size != -1)
					sharks.push_back(A[a][b]);
			}
		}
		
		for (int k = 0; k < sharks.size(); k++) {
			for (int s = 0; s < sharks[k].s; s++) {
				int ny = sharks[k].y + my[sharks[k].dir];
				int nx = sharks[k].x + mx[sharks[k].dir];
				if (ny < 0 || ny >= Y || nx < 0 || nx >= X) {
					sharks[k].dir = (sharks[k].dir + 2) % 4;
					s--;
				}
				else {
					sharks[k].y = ny;
					sharks[k].x = nx;
				}
			}
		}
		
		
	}
	cout << ans;
	return 0;
}