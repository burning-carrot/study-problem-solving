#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int answer;
int check(int start, int originWeakSize, vector<int>& weak, vector<int>& dist) {
  int ret = 0;  // 탐색한 사람 수
  int weak_idx = start;
  int cnt = 0;  // 탐색한 취약지역 수
  for (int dist_idx = 0; dist_idx < dist.size(); dist_idx++) {
    int to = weak[weak_idx] + dist[dist_idx];
    ret++;
    if (ret >= answer) return ret;
    while (to >= weak[weak_idx]) {
      weak_idx++;
      cnt++;
      if (cnt == originWeakSize) return ret;
    }
  }
  return INT_MAX;
}

int solution(int n, vector<int> weak, vector<int> dist) {
  answer = INT_MAX;
  int originWeakSize = weak.size();
  for (int i = 0, size = weak.size() - 1; i < size; i++) {
    weak.push_back(weak[i] + n);
  }

  sort(dist.begin(), dist.end());
  for (int i = 0; i < originWeakSize; i++) {
    do {
      answer = min(answer, check(i, originWeakSize, weak, dist));
    } while (next_permutation(dist.begin(), dist.end()));
  }
  if (answer == INT_MAX) {
    return -1;
  }
  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n1 = 12;
  vi weak1 = {1, 5, 6, 10};
  vi dist1 = {1, 2, 3, 4};

  int n2 = 12;
  vi weak2 = {1, 3, 4, 9, 10};
  vi dist2 = {3, 5, 7};

  int n3 = 30;
  vi weak3 = {0, 3, 11, 21};
  vi dist3 = {10, 4};

  int n4 = 50;
  vi weak4 = {1};
  vi dist4 = {6};
  cout << solution(n1, weak1, dist1) << endl;
  cout << solution(n2, weak2, dist2) << endl;
  cout << solution(n3, weak3, dist3) << endl;
  cout << solution(n4, weak4, dist4) << endl;

  return 0;
}