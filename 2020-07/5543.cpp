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
	int a = 9999, b = 9999;
	for (int i = 0; i < 3; i++) {
		int t;
		cin >> t;
		a = min(a, t);
	}
	for (int i = 0; i < 2; i++) {
		int t;
		cin >> t;
		b = min(b, t);
	}
	cout << a + b - 50;
	return 0;
}