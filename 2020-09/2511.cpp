#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
vector<int> A, B;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	A.resize(10);
	B.resize(10);
	for (int i = 0; i < 10; i++) cin >> A[i];
	for (int i = 0; i < 10; i++) cin >> B[i];

	int a, b;
	a = b = 0;
	int flag = 0;
	for (int i = 0; i < 10; i++) {
		if (A[i] > B[i]) {
			a += 3;
			flag = -1;
		}
		else if (A[i] < B[i]) {
			b += 3;
			flag = 1;
		}
		else {
			a++;
			b++;
		}
	}

	cout << a << " " << b << "\n";
	if (a > b) cout << "A";
	else if (a < b) cout << "B";
	else {
		if (flag == -1) cout << "A";
		else if (flag == 1) cout << "B";
		else cout << "D";
	}
	return 0;
}