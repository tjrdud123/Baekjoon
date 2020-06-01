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
int f(int n) {
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	return f(n - 1) + f(n - 2);
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}