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
	cin >> str;
	for (int i = 0; i < 26; i++) {
		char c = 'a' + i;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == c) {
				cout << j << " ";
				break;
			}
			if (j == str.size() - 1) {
				cout << -1 << " ";
			}
		}
	}
	return 0;
}