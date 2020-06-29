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
int N;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int ans = 0;
	int t = 1;
	int z = 10;
	for (int i = 1; i <= N; i++) {
		if (i == z) {
			t++;
			z *= 10;
		}
		ans += t;
	}
	cout << ans;

	return 0;
}