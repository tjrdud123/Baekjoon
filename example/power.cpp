#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <ctype.h>
using namespace std;
int power(int x, int n) {
	if (n == 1) return x;
	int hx = power(x, n / 2);
	if (n % 2) return hx * hx * x;
	return hx * hx;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << power(2, 10);
	return 0;
}