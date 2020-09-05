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
map<int, int> m;
vector<bool> isInspected;
vector<bool> isPicked;
int ans = 100;
bool isCompleted(vector<int> weak) {
	for (int i = 0; i < weak.size(); i++) {
		if (isInspected[i] == false) return false;
	}
	return true;
}
void subsol(int n, vector<int> weak, vector<int> dist, int idx, int cnt) {
	if (isCompleted(weak)) {
		ans = min(ans, cnt);
		return;
	}
	if (idx == weak.size()) return;
	if (isInspected[idx]) {
		subsol(n, weak, dist, idx + 1, cnt);
		return;
	}
	int w = weak[idx];
	vector<bool> B = isInspected;
	for (int i = 0; i < dist.size(); i++) {
		if (isPicked[i]) continue;
		isPicked[i] = true;
		int d = dist[i];
		int tIdx = idx;
		for (int j = 0; j <= d; j++) {
			int loc = (w + j) % n;
			if (m[loc] != 0) {
				isInspected[m[loc] - 1] = true;
			}
		}
		subsol(n, weak, dist, idx + 1, cnt + 1);
		isPicked[i] = false;
	}
	isInspected = B;
}
int solution(int n, vector<int> weak, vector<int> dist) {
	isInspected.assign(weak.size(), false);
	isPicked.assign(dist.size(), false);
	
	for (int i = 0; i < weak.size(); i++) {
		weak.push_back(weak[0]);
		weak.erase(weak.begin());
		m.clear();
		for (int j = 0; j < weak.size(); j++) m[weak[j]] = j + 1;
		subsol(n, weak, dist, 0, 0);
	}
	
	if (ans == 100) return -1;
	return ans;
}