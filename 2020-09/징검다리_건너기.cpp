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
int solution(vector<int> stones, int k) {
	int N = stones.size();
	int minn = 2000000001, maxx = -1;
	for (int i = 0; i < N; i++) {
		minn = min(minn, stones[i]);
		maxx = max(maxx, stones[i]);
	}
	if (k == 1) return minn;
	if (k == N) return maxx;
	int ans;
	priority_queue<int> pq;
	priority_queue<int> temp;
	for (int i = 0; i < k; i++) pq.push(stones[i]);
	ans = pq.top();
	for (int i = 1; i < N - k + 1; i++) {
		pq.push(stones[i + k - 1]);
		temp.push(stones[i - 1]);
		while (!pq.empty() && !temp.empty() && (pq.top() == temp.top())) {
			pq.pop();
			temp.pop();
		}
		ans = min(ans, pq.top());
	}
	return ans;
}
