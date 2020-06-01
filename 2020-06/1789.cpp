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

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double S;
	cin >> S;
	double temp = 0LL;
	for (double i = 1; ; i++) {
		temp += i;
		if (temp > S) {
			cout << i - 1;
			break;
		}
	}
	return 0;
}