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
vector<long long> A;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(N + 1);
	A[0] = 0;
	A[1] = A[2] = 1;
	for (int i = 3; i <= N; i++)
		A[i] = A[i - 2] + A[i - 1];
	cout << A[N];
	return 0;
}