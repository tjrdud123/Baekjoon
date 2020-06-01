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
	int T, R;
	string str;
	cin >> T;
	while (T--) {
		cin >> R >> str;
		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < R; j++) {
				cout << str[i];
			}
		}cout << endl;
	}
	return 0;
}