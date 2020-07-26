#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
vector<int> v(4, 0);
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());
		if (v[0] == 1)
			cout << "E\n";
		else if (v[1] == 1)
			cout << "A\n";
		else if (v[2] == 1)
			cout << "B\n";
		else if (v[3] == 1)
			cout << "C\n";
		else
			cout << "D\n";
	}
	return 0;
}