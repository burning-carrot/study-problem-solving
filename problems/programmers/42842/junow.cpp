#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<int> solution(int brown, int yellow) {
  vector<int> answer;

  for (int h = 3; h < (brown + yellow) / 2; h++) {
    if ((brown + yellow) % h != 0) continue;
    int w = (brown + yellow) / h;

    if ((w - 2) * (h - 2) == yellow) {
      answer.push_back(w);
      answer.push_back(h);
      return answer;
    }
  }
  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  auto answer = solution(10, 2);
  for (auto& _answer : answer) {
    cout << _answer << " ";
  }
  return 0;
}