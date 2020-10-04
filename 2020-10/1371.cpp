#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int, char> > A;
bool cmp(pair<int, char> a, pair<int, char> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	A.resize(26);
	for (int i = 0; i < 26; i++) {
		A[i].first = 0;
		A[i].second = 'a' + i;
	}
	while (cin >> str) {
		for (int i = 0; i < str.size(); i++) {
			char ch = str[i];
			A[ch - 'a'].first++;
		}
	}
	sort(A.begin(), A.end());
	int maxx = 0;
	for (int i = 0; i < 26; i++) maxx = max(maxx, A[i].first);
	for (int i = 0; i < 26; i++) {
		if (A[i].first == maxx) cout << A[i].second;
	}
	return 0;
}