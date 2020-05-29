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
int N;
stack<int> s;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		int value;
		cin >> str;
		if (str == "push") {
			cin >> value;
			s.push(value);
		}
		else if (str == "top") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else
				cout << s.top() << "\n";
		}
		else if (str == "pop") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top() << "\n";
				s.pop();
			}
			
		}
		else if (str == "size") {
			cout << s.size() << "\n";
		}
		else if (str == "empty") {
			if (s.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
	}
	return 0;
}