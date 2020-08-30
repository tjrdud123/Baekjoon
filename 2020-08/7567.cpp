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
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int ans = 10;
	for (int i = 1; i < str.size(); i++) {
		if (str[i - 1] == '(' && str[i] == '(') ans += 5;
		else if (str[i - 1] == ')' && str[i] == ')') ans += 5;
		else ans += 10;
	}
	cout << ans;
	return 0;
}