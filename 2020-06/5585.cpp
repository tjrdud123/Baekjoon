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
	N = 1000 - N;
	int ans = 0;
	while (N) {
		ans++;
		if (N >= 500) {
			N -= 500;
		}
		else if (N >= 100) {
			N -= 100;
		}
		else if (N >= 50) {
			N -= 50;
		}
		else if (N >= 10) {
			N -= 10;
		}
		else if (N >= 5) {
			N -= 5;
		}
		else {
			N -= 1;
		}
	}
	cout << ans;
	return 0;
}