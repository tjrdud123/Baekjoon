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
string solution(int n, int t, int m, vector<string> timetable) {
	vector<int> crew;
	for (int i = 0; i < timetable.size(); i++) {
		string time = timetable[i];
		int HH = stoi(time.substr(0, 2));
		int MM = stoi(time.substr(3, 2));
		crew.push_back(HH * 60 + MM);
	}
	sort(crew.begin(), crew.end(), cmp);
	queue<int> q;
	int idx = 0;
	int start = 540;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int time = start + t * i;
		
		for (int j = idx; j < crew.size(); j++) {
			if (crew[j] <= time) {
				//printf("%d %d\n", time, crew[j]);
				q.push(crew[j]);
				if (q.size() == m) {
					ans = max(ans, crew[j] - 1);
				}
			}
			else {
				idx = j;
				break;
			}
			if (j == crew.size() - 1) idx = crew.size();
		}
		if (q.size() < m) ans = max(ans, time);
		if (q.size() < m) {
			while (q.empty() == false) q.pop();
		}
		else {
			for (int j = 0; j < m; j++) {
				ans = max(ans, q.front() - 1);
				q.pop();
			}
		}
	}
	if (ans > 540 + (n - 1) * t) ans = 540 + (n - 1) * t;
	string ret;
	int H = ans / 60;
	int M = ans % 60;
	if (H < 10) ret += "0";
	ret += to_string(H);
	ret += ":";
	if (M < 10) ret += "0";
	ret += to_string(M);
	return ret;
}