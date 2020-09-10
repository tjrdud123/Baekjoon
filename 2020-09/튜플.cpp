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
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else return a.second > b.second;
}
vector<int> solution(string s) {
	int N = s.size();
	vector<pair<int, int> > cnt(100001);
	for (int i = 0; i < 100001; i++) cnt[i] = make_pair(i, 0);
	int t = 0;
	for (int i = 0; i < N; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			t *= 10;
			t += s[i] - '0';
		}
		else {
			cnt[t].second++;
			t = 0;
		}
	}
	sort(cnt.begin(), cnt.end(), cmp);
	vector<int> ans;
	for (int i = 0; i < 100001; i++) {
		if (cnt[i].second && cnt[i].first != 0) {
			ans.push_back(cnt[i].first);
		}
	}
	return ans;
}
