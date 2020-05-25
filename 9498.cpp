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
	int N;
	cin >> N;
	if (N >= 90)
		cout << "A";
	else if (N >= 80)
		cout << "B";
	else if (N >= 70)
		cout << "C";
	else if (N >= 60)
		cout << "D";
	else
		cout << "F";

	return 0;
}