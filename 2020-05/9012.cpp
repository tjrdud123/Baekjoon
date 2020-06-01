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
int T;
stack<char> s;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') {
				s.push(str[i]);
			}
			else {
				if (s.empty()) {
					cout << "NO\n";
					break;
				}
				else
					s.pop();
			}
			if (i == str.size() - 1) {
				if (s.empty()) {
					cout << "YES\n";
				}
				else
					cout << "NO\n";
			}
		}
		while (!s.empty())
			s.pop();
	}

	return 0;
}