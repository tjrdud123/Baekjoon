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
	int N;
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	long long t = 1ll;
	for (int i = 1; ; i++) {
		t += (long long)6 * i;
		if ((long long)N <= t) {
			cout << i + 1 << endl;
			break;
		}
	}
	return 0;
}