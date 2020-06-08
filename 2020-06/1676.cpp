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
	int cnt[2] = { 0, 0 };
	for (int i = 2; i <= N; i++) {
		int n = i;
		while (1) {
			if (n % 2 == 0) {
				cnt[0]++;
				n /= 2;
			}
			if (n % 5 == 0) {
				cnt[1]++;
				n /= 5;
			}
				
			if (n % 2 && n % 5)
				break;
		}
	}
	cout << min(cnt[0], cnt[1]);
	return 0;
}