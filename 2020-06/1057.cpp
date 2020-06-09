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
int N, F;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> F;
	N /= 100;
	N *= 100;
	for (int i = 0; i <= 100; i++) {
		int n = N + i;
		if (n % F == 0) {
			if (i < 10) {
				cout << "0" << i;
			}
			else {
				cout << i;
			}
			break;
		}
	}
	return 0;
}