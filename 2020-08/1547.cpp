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
	cin >> N;
	int ans = 1;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a != b) {
			if (a == ans) {
				ans = b;
			}
			else if (b == ans) {
				ans = a;
			}
		}
	}
	cout << ans;
	return 0;
}