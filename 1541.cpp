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
string str;
int ans = 0;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	int temp = 0;
	int sign = 1;
	for (int i = 0; ; i++) {
		if (i == str.size()) {
			ans += sign * temp;
			break;
		}
		if (str[i] == '-') {
			ans += sign * temp;
			sign = -1;
			temp = 0;
		}
		else if (str[i] == '+') {
			ans += sign * temp;
			temp = 0;
		}
		else {
			temp *= 10;
			temp += (int)(str[i] - '0');
		}
	}
	cout << ans << endl;
	return 0;
}