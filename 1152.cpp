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

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	getline(cin, str);
	int cnt = 0;
	if (str.size() == 1 && str[0] == ' ') {
		cout << 0;
		return 0;
	}
	for (int i = 1; i < str.size() - 1; i++) {
		if (str[i] == ' ')
			cnt++;
	}
	cout << cnt + 1;
	return 0;
}