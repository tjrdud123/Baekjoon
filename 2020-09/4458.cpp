#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	string str;
	getline(cin, str);
	for (int i = 0; i < N; i++) {
		
		getline(cin, str);
		if ('a' <= str[0] && str[0] <= 'z') str[0] -= 32;
		cout << str << "\n";
	}
	return 0;
}