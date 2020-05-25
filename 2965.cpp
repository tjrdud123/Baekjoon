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
	int a, b, c;
	int start, end;
	cin >> a >> b >> c;
	if (b - a > c - b) {
		start = a;
		end = b;
	}
	else {
		start = b;
		end = c;
	}
	cout << end - start - 1;
	return 0;
}