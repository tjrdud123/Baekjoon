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
int solution(string s) {
	int n = s.size();
	vector<string> v;
	int answer = n;
	for (int i = 1; i <= n; i++) {
		string compStr = "";
		int idx = 0;
		while (idx < n) {
			v.push_back(s.substr(idx, i));
			idx += i;
		}
		
		idx = 0;
		while (idx < v.size()) {
			string tStr = v[idx];
			int tN;
			for (tN = 1; idx + tN < v.size(); tN++) {
				if (tStr == v[idx + tN]) {}
				else break;
			}
			if (tN > 1) compStr += to_string(tN);
			compStr += tStr;
			idx += tN;
		}
		cout << compStr << "\n";
		if (answer > compStr.size()) answer = compStr.size();
		v.clear();
	}
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << solution("abcabcabcabcdededededede");

	return 0;
}