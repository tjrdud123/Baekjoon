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
int N;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	string str;
	cin >> str;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (int)(str[i] - '0');
	}
	cout << sum;
	return 0;
}