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
int mx[6] = {0, 1, 1, 0, -1, -1};
int my[6] = {1, 1, -1, -1, -1, 1};
vector<pair<int, int> > v;
int ans = 0;
void f(int dir, int x, int y, int cnt) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == x && v[i].second == y) {
			if (cnt == N)
				ans++;
			return;
		}
	}
	if (cnt == N)
		return;
	v.push_back(make_pair(x, y));
	if (dir == 0) {
		f(1, x + mx[1], y + my[1], cnt + 1);
		f(5, x + mx[5], y + my[5], cnt + 1);
	}
	else if (dir == 1) {
		f(0, x + mx[0], y + my[0], cnt + 1);
		f(2, x + mx[2], y + my[2], cnt + 1);
	}
	else if (dir == 2) {
		f(1, x + mx[1], y + my[1], cnt + 1);
		f(3, x + mx[3], y + my[3], cnt + 1);
	}
	else if (dir == 3) {
		f(2, x + mx[2], y + my[2], cnt + 1);
		f(4, x + mx[4], y + my[4], cnt + 1);
	}
	else if (dir == 4) {
		f(3, x + mx[3], y + my[3], cnt + 1);
		f(5, x + mx[5], y + my[5], cnt + 1);
	}
	else if (dir == 5) {
		f(0, x + mx[0], y + my[0], cnt + 1);
		f(4, x + mx[4], y + my[4], cnt + 1);
	}
	v.pop_back();
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v.push_back(make_pair(0, 0));
	f(0, 0, 1, 0);
	cout << ans << endl;
	return 0;
}