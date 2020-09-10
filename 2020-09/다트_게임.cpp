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
int solution(string dartResult) {
	vector<int> scores;
	for (int i = 0; i < dartResult.size(); i++) {
		char ch = dartResult[i];
		if ('0' <= ch && ch <= '9') {
			if (dartResult[i + 1] == '0') {
				scores.push_back(10);
				i++;
			}
			else scores.push_back(ch - '0');
		}
		else if (ch == 'D') {
			scores.back() = power(scores.back(), 2);
		}
		else if (ch == 'T') {
			scores.back() = power(scores.back(), 3);
		}
		else if (ch == '*') {
			scores.back() *= 2;
			if (scores.size() > 1) scores[scores.size() - 2] *= 2;
		}
		else if (ch == '#') {
			scores.back() *= -1;
		}
	}
	int ans = 0;
	for (int i = 0; i < scores.size(); i++) {
		cout << scores[i] << "\n";
		ans += scores[i];
	}
	return ans;
}
