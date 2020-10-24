#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(int day, int width, int **blocks) {
    vector<int> h(width, 0);
    int ans = 0;
    vector<int> ll(width, 0);
    vector<int> rr(width, 0);
    for(int d = 0; d < day; d++) {
        for(int i = 0; i < width; i++) {
            h[i] += blocks[d][i];
        }
        ll[0] = h[0];
        rr[width - 1] = h[width - 1];
        for(int i = 1; i < width; i++) ll[i] = max(ll[i - 1], h[i]);
        for(int i = width - 2; i >= 0; i--) rr[i] = max(rr[i + 1], h[i]);
        
        // 시멘트 붓기
        for(int i = 1; i < width - 1; i++) {
            int height = min(ll[i - 1], rr[i + 1]);
            if(h[i] < height) {
                ans += (height - h[i]);
                h[i] = height;
            }
        }
    }
    cout << ans;
}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}