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
string conv(int n, int value) {
	// value를 n진법 string 으로
	vector<int> v;
	int a = 1;
	while (a <= value) {
		a *= n;
		v.push_back(0);
	}
	
	a /= n;
	int idx = 0;
	while (value) {
		v[idx++] = (value / a);
		value -= (a * (value / a));
		a /= n;
	}
	if (v.empty()) return "0";
	string ret;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 15) ret += "F";
		else if (v[i] == 14) ret += "E";
		else if (v[i] == 13) ret += "D";
		else if (v[i] == 12) ret += "C";
		else if (v[i] == 11) ret += "B";
		else if (v[i] == 10) ret += "A";
		else ret += to_string(v[i]);
	}
	return ret;
}
string solution(int n, int t, int m, int p) {
	string str;
	for (int i = 0; str.size() < t * m; i++) {
		str += conv(n, i);
	}
	//cout << str << "\n";
	string ret;
	for (int i = 0; i < t; i++) {
		ret += str[m * i + p - 1];
	}
	return ret;
}