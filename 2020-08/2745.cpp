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
int N;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str >> N;
	int ans = 0;
	int w = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		char ch = str[i];
		int n;
		if ('0' <= ch && ch <= '9') {
			n = ch - '0';
		}
		else if ('A' <= ch && ch <= 'Z') {
			n = ch - 'A' + 10;
		}
		ans += n * w;
		w *= N;
	}

	cout << ans;
	return 0;
}