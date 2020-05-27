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
int a, b;
bool isPrime[10001];
void era() {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	int n = sqrt(10000);
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 10000; j += i)
				isPrime[j] = false;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	era();
	cin >> a >> b;
	int flag = 0;
	int sum = 0;
	int minV = 112312312;
	for (int i = a; i <= b; i++) {
		if (isPrime[i]) {
			flag = 1;
			sum += i;
			minV = min(minV, i);
		}
	}
	if (flag) {
		cout << sum << "\n" << minV;
	}
	else
		cout << -1;
	return 0;
}