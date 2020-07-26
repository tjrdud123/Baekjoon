#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;
		sum += max(temp, 40);
	}
	cout << sum / 5;
	return 0;
}