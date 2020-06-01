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
	int n = sqrt(N);
	for (int i = 2; i <= n; i++) {
		while (N % i == 0) {
			cout << i << "\n";
			N /= i;
		}
	}
	if (N != 1)
		cout << N;
	return 0;
}