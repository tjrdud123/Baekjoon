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

string conv(int n) {
	string t;
	if (n == 0) return "0";
	while (n > 1) {
		char ch = n % 2;
		ch += '0';
		t += ch;
		n /= 2;
	}
	t += "1";
	string ret;
	for (int i = t.size() - 1; i >= 0; i--)
		ret += t[i];
	return ret;
}
string addZero(string s) {
	string ret;
	for (int i = 0; i < 3 - s.size(); i++)
		ret += "0";
	return ret + s;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string oct;
	cin >> oct;
	//for (int i = 0; i < 8; i++) cout << conv(i) << "\n";
	cout << conv((int)oct[0] - '0');
	for (int i = 1; i < oct.size(); i++) {
		cout << addZero(conv((int)oct[i] - '0'));
	}
	return 0;
}