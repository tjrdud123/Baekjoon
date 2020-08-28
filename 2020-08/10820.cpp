#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	while (getline(cin, str)) {
		int a, b, c, d;
		a = b = c = d = 0;
		for (int i = 0; i < str.size(); i++) {
			if ('a' <= str[i] && str[i] <= 'z') a++;
			else if ('A' <= str[i] && str[i] <= 'Z') b++;
			else if ('0' <= str[i] && str[i] <= '9') c++;
			else if (str[i] == ' ') d++;
		}
		cout << a << " " << b << " " << c << " " << d << "\n";
	}
	return 0;
}