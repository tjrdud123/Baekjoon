#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(void) {
	vector<int> ans;
	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;
		if (str.find("FBI") != string::npos) {
			ans.push_back(i);
		}
	}
	if (ans.empty()) {
		cout << "HE GOT AWAY!";
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] + 1 << " ";
		}
	}
	return 0;
}