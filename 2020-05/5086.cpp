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
	int a, b;
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		if (a < b && b % a == 0) {
			cout << "factor\n";
		}
		else if (a > b && a % b == 0) {
			cout << "multiple\n";
		}
		else {
			cout << "neither\n";
		}
	}

	return 0;
}