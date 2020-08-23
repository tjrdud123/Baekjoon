#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int cache[101][101];
string W, S;
int match(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])) return ret = match(w + 1, s + 1);

	if (w == W.size()) return ret = (s == S.size());

	if (W[w] == '*') {
		if (match(w + 1, s) || (s < S.size() && match(w, s + 1))) return ret = 1;
	}
	return ret = 0;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> W;
	int T;
	cin >> T;
	while (T--) {
		memset(cache, -1, sizeof(cache));
		cin >> S;
		if (match(0, 0))
			cout << S << "\n";
	}
	return 0;
}