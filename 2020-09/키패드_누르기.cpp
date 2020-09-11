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
bool cmp(int a, int b) {
	return a < b;
}
int dist(int y1, int x1, int y2, int x2) {
	return abs(y1 - y2) + abs(x1 - x2);
}
string solution(vector<int> numbers, string hand) {
	string ans;
	map<int, pair<int, int> > loc;
	int idx = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			loc[idx++] = make_pair(i, j);
		}
	}
	loc[0] = make_pair(3, 1);
	loc[-1] = make_pair(3, 0);
	loc[-2] = make_pair(3, 2);
	int left = -1, right = -2;
	for (int i = 0; i < numbers.size(); i++) {
		int n = numbers[i];
		if (n == 1 || n == 4 || n == 7) {
			ans += "L";
			left = n;
		}
		else if (n == 3 || n == 6 || n == 9) {
			ans += "R";
			right = n;
		}
		else {
			pair<int, int> target = loc[n];
			int d1 = dist(loc[left].first, loc[left].second, target.first, target.second);
			int d2 = dist(loc[right].first, loc[right].second, target.first, target.second);
			if (d1 == d2) {
				if (hand == "left") {
					ans += "L";
					left = n;
				}
				else {
					ans += "R";
					right = n;
				}
			}
			else if (d1 > d2) {
				
				ans += "R";
				right = n;
			}
			else {
				ans += "L";
				left = n;
			}
		}
	}
	return ans;
}