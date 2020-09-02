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
struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		if (p1.first == p2.first) return p1.second > p2.second;
		return p1.first > p2.first;
	}
};
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp > pq;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int value; cin >> value;
		if (value == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top().first * pq.top().second << "\n";
				pq.pop();
			}
			continue;
		}
		if (value < 0) {
			pq.push(make_pair(-value, -1));
		}
		else {
			pq.push(make_pair(value, 1));
		}
	}
	return 0;
}
