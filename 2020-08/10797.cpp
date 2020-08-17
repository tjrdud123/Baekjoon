#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		int t;
		cin >> t;
		if (N == t)
			ans++;
	}
	cout << ans;
	return 0;
}