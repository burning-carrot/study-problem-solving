#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool check(deque<pair<int, int>>& dq, int p) {
  for (auto& v : dq) {
    if (v.first > p) return false;
  }
  return true;
}
int solution(vector<int> priorities, int location) {
  int answer = 0;
  deque<pair<int, int>> dq;
  for (int i = 0, size = priorities.size(); i < size; i++) {
    dq.push_back({priorities[i], i});
  }

  while (true) {
    auto cur = dq.front();
    dq.pop_front();
    if (check(dq, cur.first)) {
      answer++;
      if (cur.second == location) break;
    } else {
      dq.push_back(cur);
    }
  }

  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> priorities1 = {2, 1, 3, 2};
  int loca1 = 2;
  vector<int> priorities2 = {1, 1, 9, 1, 1, 1};
  int loca2 = 0;
  cout << solution(priorities2, loca2) << endl;
  return 0;
}
