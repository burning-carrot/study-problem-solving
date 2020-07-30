#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<int> solution(vector<int> prices) {
  vector<int> answer;
  stack<pii> s;
  int curTime = 0, size = prices.size();
  answer.resize(size, 0);

  for (int i = 0; i < size; i++) {
    curTime++;
    if (s.empty() || prices[i] >= s.top().first) {
      s.push({prices[i], curTime});
    } else {
      while (!s.empty() && s.top().first > prices[i]) {
        auto out = s.top();
        s.pop();
        answer[out.second - 1] = curTime - out.second;
      }
      s.push({prices[i], curTime});
    }
  }

  while (!s.empty()) {
    auto out = s.top();
    s.pop();
    answer[out.second - 1] = curTime - out.second;
  }
  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vi v = {1, 2, 3, 2, 3};
  auto ans = solution(v);
  for (auto& v : ans) cout << v << " ";
  cout << endl;
  return 0;
}