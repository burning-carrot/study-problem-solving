#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N, M, A, B, C, S, E, maxv;
vector<vector<pii>> v;
bool visit[10001];

bool bfs(int m) {
  queue<int> q;
  fill(visit, visit + 10001, false);

  q.push(S);

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (cur == E) {
      return true;
    }

    for (int i = 0, len = v[cur].size(); i < len; i++) {
      auto next = v[cur][i];
      if (visit[next.first]) continue;
      if (next.second < m) continue;

      visit[next.first] = true;
      q.push(next.first);
    }
  }

  return false;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  v.resize(N + 1);

  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    v[A].push_back({B, C});
    v[B].push_back({A, C});
    maxv = max(maxv, C);
  }

  cin >> S >> E;
  int l = 0, r = maxv;
  int ans = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (bfs(m)) {
      l = m + 1;
      ans = max(ans, m);
    } else {
      r = m - 1;
    }
  }

  cout << ans << "\n";

  return 0;
}