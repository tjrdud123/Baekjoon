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
int N, L, R;
int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };
vector<vector<int> > A;
bool visited[50][50];
vector<pair<int, int> > locs;
int dfs(int y, int x) {
	visited[y][x] = true;

	locs.push_back(make_pair(y, x));

	int ret = A[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < N) {
			if (visited[ny][nx] == false && L <= abs(A[ny][nx] - A[y][x]) && abs(A[ny][nx] - A[y][x]) <= R)
				ret += dfs(ny, nx);
		}
	}
	return ret;
}
bool dfsAll() {
	int total;
	int flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				
				locs.clear();
				
				total = dfs(i, j);
				int n = locs.size();
				if (n > 1) {
					flag = true;
					for (int k = 0; k < n; k++) {
						
						int value = total / n;
						A[locs[k].first][locs[k].second] = value;
					}
				}
			}
		}
	}
	
	return flag;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		A[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	
	memset(visited, 0, sizeof(visited));
	int ans = 0;
	while (dfsAll()) {
	
		ans++;
		memset(visited, 0, sizeof(visited));
	}
	cout << ans;
	return 0;
}