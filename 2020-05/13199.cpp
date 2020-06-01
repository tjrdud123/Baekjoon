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
int T, P, M, F, C;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> P >> M >> F >> C;
		int a, b;
		a = (M / P * C) / F;
		int t = M / P * C;
		b = 0;
		if (t > F) {
			b += (t - F) / (F - C) + 1;
			cout << b - a << endl;
		}	
		else
			cout << 0 << endl;
		

	}
	return 0;
}