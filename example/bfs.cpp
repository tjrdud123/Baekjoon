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

vector<vector<int> > adj;
vector<int> bfs(int start) {
	vector<bool> discovered(adj.size(), false);
	queue<int> q;
	vector<int> order;

	discovered[start] = true;
	q.push(start);

	while (q.empty() == false) {
		int here = q.front();
		q.pop();

		order.push_back(here);
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];

			if (discovered[there] == false) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
	return order;
}

// 2차원 배열에서 bfs
vector<vector<int> > A;
vector<pair<int, int> > bfs2(int y, int x) {
	vector<pair<int, int> > order;
	vector<vector<bool> > discovered;
	discovered.resize(A.size());
	for (int i = 0; i < A.size(); i++) discovered[i].assign(A[0].size(), false);
	discovered[y][x] = true;

	queue<pair<int, int> > q;
	q.push(make_pair(y, x));

	int my[4] = { -1, 0, 1, 0 };
	int mx[4] = { 0, 1, 0, -1 };

	while (q.empty() == false) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		order.push_back(make_pair(y, x));

		for (int i = 0; i < 4; i++) {
			int ny = y + my[i];
			int nx = x + mx[i];
			if (0 <= ny && ny < A.size() && 0 <= nx && nx < A[0].size()) {
				// 2차원 배열 A에서 값이 1인곳만 순회(선택)
				if (A[ny][nx] == 1 && discovered[ny][nx] == false) {
					discovered[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	return order;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	A.resize(3);
	for (int i = 0; i < 3; i++) A[i].assign(3, 1);
	vector<pair<int, int> > v = bfs2(0, 0);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}