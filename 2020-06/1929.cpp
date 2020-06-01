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
bool isPrime[1000001];
void era() {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	int n = sqrt(1000000);
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 1000000; j += i)
				isPrime[j] = false;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	era();
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (isPrime[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}