#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int R, B;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> B;
	for (int i = 3; ; i++) {
		for (int j = 3; ; j++) {
			if (i * j > R + B)
				break;
			if (i * j == R + B) {
				if ((i - 2) * (j - 2) == B) {
					cout << max(i, j) << " " << min(i, j);
					return 0;
				}
			}
		}
	}
	return 0;
}