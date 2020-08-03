#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  queue<int> q;

  for (int i = 0, size = progresses.size(); i < size; i++) {
    int t = (100 - progresses[i]) / speeds[i] + 1;
    if ((100 - progresses[i]) % speeds[i] == 0) t--;
    q.push(t);
  }

  while (!q.empty()) {
    auto cur = q.front();
    int cnt = 1;
    q.pop();

    while (!q.empty() && q.front() <= cur) {
      cnt++;
      q.pop();
    }

    answer.push_back(cnt);
  }

  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vi progresses = {93, 30, 55};
  vi speeds = {1, 30, 5};
  vector<int> ans = solution(progresses, speeds);

  for (auto& v : ans) {
    cout << v << " ";
  }
  cout << endl;

  return 0;
}