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
int N, K;
queue<int> q;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		q.push(i);
	vector<int> ans;
	int t;
	while (!q.empty()) {
		for (int i = 0; i < K - 1; i++) {
			t = q.front();
			q.pop();
			q.push(t);
		}
		t = q.front();
		q.pop();
		ans.push_back(t);
	}
	cout << "<";
	for (int i = 0; i < ans.size() - 1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans.back() << ">";
	return 0;
}