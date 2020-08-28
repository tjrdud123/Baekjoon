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
string str;
stack<int> s;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[') s.push(str[i]);
		else if (str[i] == ')') {
			if (s.empty() == false && s.top() == '(') {
				s.pop();
			}
			else {
				cout << 0;
				return 0;
			}
		}
		else if (str[i] == ']') {
			if (s.empty() == false && s.top() == '[') {
				s.pop();
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}
	if (!s.empty()) {
		cout << 0;
		return 0;
	}
	while (!s.empty())
		s.pop();
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push(-2);
		else if (str[i] == '[') s.push(-3);
		else if (str[i] == ')') {
			int sum = 0;
			while (s.top() > 0) {
				sum += s.top();
				s.pop();
			}
			s.pop();
			if (sum) s.push(sum * 2);
			else s.push(2);
		}
		else if (str[i] == ']') {
			int sum = 0;
			while (s.top() > 0) {
				sum += s.top();
				s.pop();
			}
			s.pop();
			if (sum) s.push(sum * 3);
			else s.push(3);
		}
	}
	int ans = 0;
	while (!s.empty()) {
		if (s.top() < 0) {
			cout << 0;
			return 0;
		}
		ans += s.top();
		s.pop();
	}
	cout << ans;
	return 0;
}