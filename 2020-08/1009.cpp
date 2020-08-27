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
using namespace std;
int T;
int power(int a, int b) {
	if (b == 1) return a % 10;
	if (b % 2 == 0) {
		int ret = power(a, b / 2);
		ret %= 10;
		return (ret * ret) % 10;
	}
	else {
		int ret = power(a, b / 2);
		ret %= 10;
		return (ret * ret * a) % 10;
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--) {
		int a, b;
		cin >> a >> b;
		int res = power(a, b);
		if (res) cout << res << "\n";
		else cout << 10 << "\n";
	}
	return 0;
}