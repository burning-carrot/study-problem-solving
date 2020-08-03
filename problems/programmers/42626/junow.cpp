#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

ll getNewSv(ll a, ll b) {
  return a + b * 2;
}
int solution(vector<int> scoville, int K) {
  int answer = 0;

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (auto& v : scoville) pq.push(v);

  while (!pq.empty()) {
    auto cur = pq.top();
    if (cur >= K) break;
    pq.pop();

    if (pq.empty()) break;
    auto next = pq.top();
    pq.pop();
    ll newSv = getNewSv(cur, next);
    answer++;

    pq.push(newSv);
  }
  if (pq.empty() || pq.top() < K) answer = -1;

  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vi scoville = {1, 1, 100};
  int k = 7;

  cout << solution(scoville, k) << endl;

  return 0;
}