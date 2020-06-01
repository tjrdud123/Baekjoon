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
int T, N, M;
queue < pair<int, int> > q;
vector<int> v;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			q.push(make_pair(i, t));
			v.push_back(t);
		}
		sort(v.begin(), v.end());
		int idx = v.size() - 1;
		for (int i = 1; ; ) {
			if (q.front().second == v[idx]) {
				if (q.front().first == M) {
					cout << i << "\n";
					break;
				}
				else {
					q.pop();
					i++;
				}
				idx--;
			}
			else {
				pair<int, int> t = q.front();
				q.push(t);
				q.pop();
			}
		}

		while (!q.empty())
			q.pop();
		v.clear();
	}
	return 0;
}