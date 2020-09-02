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
using namespace std;
vector<int> getPI(string N) {
	int m = N.size();
	vector<int> ret(m, 0);

	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			ret[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - ret[matched - 1];
				matched = ret[matched - 1];
			}
		}
	}
	return ret;
}
vector<int> kmp(string H, string N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPI(N);

	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m && H[begin + matched] == N[matched]) {
			matched++;
			if (matched == m) ret.push_back(begin);
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	return 0;
}
