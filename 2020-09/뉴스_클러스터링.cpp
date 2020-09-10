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
multiset<string> inter(multiset<string> s1, multiset<string> s2) {
	multiset<string> ret;
	multiset<string>::iterator iter;
	for (iter = s1.begin(); iter != s1.end(); iter++) {
		string str = *iter;
		int cnt1 = s1.count(str);
		int cnt2 = s2.count(str);
		if(ret.count(str) < min(cnt1, cnt2)) ret.insert(str);
	}
	return ret;
}
multiset<string> uni(multiset<string> s1, multiset<string> s2) {
	multiset<string> ret;
	multiset<string>::iterator iter;
	for (iter = s1.begin(); iter != s1.end(); iter++) {
		string str = *iter;
		int cnt1 = s1.count(str);
		int cnt2 = s2.count(str);
		if (ret.count(str) < max(cnt1, cnt2)) ret.insert(str);
	}
	for (iter = s2.begin(); iter != s2.end(); iter++) {
		string str = *iter;
		int cnt1 = s1.count(str);
		int cnt2 = s2.count(str);
		if (ret.count(str) < max(cnt1, cnt2)) ret.insert(str);

	}
	return ret;
}
int solution(string str1, string str2) {
	multiset<string> s1, s2;

	for (int i = 0; i < str1.size() - 1; i++) {
		string str = str1.substr(i, 2);
		if ('A' <= str[0] && str[0] <= 'Z') str[0] += 32;
		if ('A' <= str[1] && str[1] <= 'Z') str[1] += 32;
		if('a' <= str[0] && str[0] <= 'z' && 'a' <= str[1] && str[1] <= 'z')
			s1.insert(str);
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		string str = str2.substr(i, 2);
		if ('A' <= str[0] && str[0] <= 'Z') str[0] += 32;
		if ('A' <= str[1] && str[1] <= 'Z') str[1] += 32;
		if ('a' <= str[0] && str[0] <= 'z' && 'a' <= str[1] && str[1] <= 'z')
			s2.insert(str);
	}
	multiset<string> msu, msi;
	msu = uni(s1, s2);
	msi = inter(s1, s2);
	int a = msi.size();
	int b = msu.size();
	if (a == 0 && b == 0) return 65536;
	double c = (double)a / b;
	return c * 65536;
}