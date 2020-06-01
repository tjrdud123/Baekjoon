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
	vector<int> v(3, 0);
	while (1) {
		cin >> v[0] >> v[1] >> v[2];
		if (v[0] == 0)
			break;
		sort(v.begin(), v.end());
		if (v[2] * v[2] == v[0] * v[0] + v[1] * v[1]) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
	return 0;
}