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
using namespace std;
long long conv(string a, string b) {
	long long ret = 0;
	for (int i = 0; i < a.size(); i++) {
		ret *= 10LL;
		ret += (long long)a[i] - '0';
	}
	for (int i = 0; i < b.size(); i++) {
		ret *= 10LL;
		ret += (long long)b[i] - '0';
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << conv(a, b) + conv(c, d);
	return 0;
}