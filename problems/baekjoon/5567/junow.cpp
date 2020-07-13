#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
int N, M;
bool visit[501];
vvi a;

int bfs() {
  int ret = 0;
  queue<int> q;
  q.push(1);
  visit[1] = true;
  int depth = 0;

  while (!q.empty()) {
    int len = q.size();
    for (int i = 0; i < len; i++) {
      int cur = q.front();
      q.pop();

      for (int j = 0; j < a[cur].size(); j++) {
        if (visit[a[cur][j]]) continue;
        visit[a[cur][j]] = true;
        q.push(a[cur][j]);
        ret++;
      }
    }
    depth++;
    if (depth == 2) {
      break;
    }
  }

  return ret;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t1 = 0, t2 = 0;
  cin >> N >> M;
  a.resize(M + 1);
  while (M--) {
    cin >> t1 >> t2;
    a[t1].push_back(t2);
    a[t2].push_back(t1);
  }

  cout << bfs() << "\n";
  return 0;
}