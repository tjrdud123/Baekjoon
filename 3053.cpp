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
double pi = 3.14159265359;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double r;
	cin >> r;
	cout << fixed;
	cout.precision(6);

	cout << r * r * pi << endl;
	cout << r * r * 2 << endl;
	return 0;
}