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
using namespace std;
int N;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	string ans;
	cin >> ans;
	for (int i = 0; i < N - 1; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < ans.size(); j++) {
			if (ans[j] != str[j]) ans[j] = '?';
		}
	}
	cout << ans;
	return 0;
}