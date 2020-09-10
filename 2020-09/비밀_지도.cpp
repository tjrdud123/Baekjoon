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
#include <ctype.h>
using namespace std;
int power(int x, int n) {
	int ret = 1;
	for (int i = 0; i < n; i++) ret *= x;
	return ret;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> ans(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) ans[i] += " ";
		int t = power(2, n - 1);
		int a = arr1[i];
		int b = arr2[i];
		for (int j = 0; j < n; j++) {
			if (a / t) {
				ans[i][j] = '#';
				a -= t;
			}
			if (b / t) {
				ans[i][j] = '#';
				b -= t;
			}
			t /= 2;
		}
	}
	//for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
	return ans;
}
