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
bool match(string a, string b) {
	if (a.size() != b.size()) return 0;
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '*') continue;
		if (a[i] != b[i]) return false;
	}
	return true;
}
int N, M;
vector<vector<int> > A;
vector<bool> isPicked;
int ans = 0;
map<string, int> myMap;
void subsol(int idx) {
	if (idx == M) {
		string str;
		for (int i = 0; i < N; i++) {
			if (isPicked[i]) {
				str += to_string(i);
				str += "z";
			}
		}
		if (myMap[str] == 0) {
			ans++;
			myMap[str]++;
		}
		return;
	}
	for (int i = 0; i < A[idx].size(); i++) {
		int n = A[idx][i];
		if (isPicked[n] == false) {
			isPicked[n] = true;
			subsol(idx + 1);
			isPicked[n] = false;
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	N = user_id.size(), M = banned_id.size();
	isPicked.assign(N, false);
	A.resize(M);
	for (int i = 0; i < M; i++) {
		string id = banned_id[i];
		for (int j = 0; j < N; j++) {
			if (match(user_id[j], id)) A[i].push_back(j);
		}
	}
	subsol(0);
	return ans;
}
