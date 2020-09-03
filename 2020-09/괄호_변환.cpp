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
bool isBalanced(string str) {
	int l = 0, r = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') l++;
		else r++;
	}
	return l == r;
}
bool isCorrect(string str) {
	int l = 0, r = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') l++;
		else {
			if (l) l--;
			else return false;
		}
	}
	if (l) return false;
	return true;
}
string conv(string w) {
	if (w == "") return "";
	string u, v;
	int n = w.size();
	for (int i = 0; i < n; i++) {
		u += w[i];
		v = w.substr(i + 1, n);
		cout << u << "   " << v << "\n";
		if (isBalanced(u) && isBalanced(v)) break;
	}
	if (isCorrect(u)) {
		v = conv(v);
		return u + v;
	}
	else {
		string newStr = "(";
		newStr += conv(v);
		newStr += ")";
		string temp;
		for (int i = 1; i < u.size() - 1; i++) temp += u[i];
		u = temp;
		for (int i = 0; i < u.size(); i++) {
			if (u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}
		return newStr + u;
	}
}
string solution(string p) {
	return conv(p);
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	

	return 0;
}