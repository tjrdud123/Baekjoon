#include <math.h>
#include <stdio.h>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <utility>
using namespace std;
stack<char> s;
string str;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		getline(cin, str);
		if (str[0] == '.')
			break;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				s.push(str[i]);
			else if (str[i] == '[')
				s.push(str[i]);
			else if (str[i] == ')') {
				if (s.empty()) {
					cout << "no\n";
					break;
				}
				else {
					if (s.top() == '(') {
						s.pop();
					}
					else {
						cout << "no\n";
						break;
					}
				}
			}
			else if (str[i] == ']') {
				if (s.empty()) {
					cout << "no\n";
					break;
				}
				else {
					if (s.top() == '[') {
						s.pop();
					}
					else {
						cout << "no\n";
						break;
					}
				}
			}
			if (i == str.size() - 1) {
				if (s.empty()) {
					cout << "yes\n";
				}
				else
					cout << "no\n";
			}
		}
		while (!s.empty())
			s.pop();
		
	}
	return 0;
}