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
int gcd(int a, int b) {
	if (b % a == 0)
		return a;
	return gcd(b % a, a);
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	cout << gcd(a, b) << "\n" << a * b / gcd(a, b);

	return 0;
}