#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
string A, B;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	long long ans = 0ll;
	for (int i = 0; i < A.size(); i++) {
		int a = A[i] - '0';
		for (int j = 0; j < B.size(); j++) {
			int b = B[j] - '0';
			ans += (long long)a * (long long)b;
		}
	}
	cout << ans;
	return 0;
}