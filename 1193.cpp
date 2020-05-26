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
	int sum = 0;
	int i;
	for (i = 1; ; i++) {
		sum += i;
		if (N <= sum) {
			N = N - sum + i;
			break;
		}
	}
	if (i % 2) {
		cout << i + 1 - N << "/" << N;
	}
	else {

		cout << N << "/" << i + 1 - N;
	}
	return 0;
}