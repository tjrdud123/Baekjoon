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

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}
	string str;
	cin >> str;
	sort(v.begin(), v.end());
	for (int i = 0; i < str.size(); i++) {
		cout << v[str[i] -'A'] << " ";
	}
	return 0;
}
