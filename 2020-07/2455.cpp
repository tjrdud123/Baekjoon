#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int ans = -1;
	int total = 0;
	for (int i = 0; i < 4; i++) {
		int a, b;
		cin >> a >> b;
		total -= a;
		ans = max(ans, total);
		total += b;
		ans = max(ans, total);
	}
	cout << ans;
	return 0;
}