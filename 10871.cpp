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
	int N, X;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp < X)
			cout << temp << " ";
	}
	return 0;
}