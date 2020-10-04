#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int A = 1, B = 0;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int t = A;
		A = B;
		B += t;
	}
	cout << A << " " << B;
	return 0;
}