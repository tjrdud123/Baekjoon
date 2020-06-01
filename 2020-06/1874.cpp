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
vector<int> A;
vector<char> ans;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int idx = 0;
	for (int i = 1; i <= N, idx < N;) {
		if (!s.empty()) {
			if (s.top() == A[idx]) {
				s.pop();
				idx++;
				ans.push_back('-');
			}
			else {
				if (i > N) {
					cout << "NO\n";
					return 0;
				}
				s.push(i++);
				ans.push_back('+');
			}
				
		}
		else {
			s.push(i++);
			ans.push_back('+');
		}
			
	}
	if (s.empty()) {
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << "\n";
	}
	else {
		cout << "NO";
	}
	return 0;
}