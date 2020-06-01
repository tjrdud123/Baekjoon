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
int T, h;
string str;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> h;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'c') {
				h++;
			}
			else if (str[i] == 'b') {
				h--;
			}
		}
		cout << "Data Set " << t << ":" << endl;
		cout << h << "\n\n";
	}
	return 0;
}