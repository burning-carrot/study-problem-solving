#include <bits/stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int S;
bool visit[1001][1001];
int bfs() {
  int ret = 0;
  queue<pii> q;

  q.push({1, 0});
  visit[1][0] = true;

  while (!q.empty()) {
    int len = q.size();
    while (len--) {
      pii cur = q.front();
      q.pop();
      int v = cur.first;
      int cb = cur.second;
      if (v == S) {
        return ret;
      }
      if (!visit[v][v]) {
        q.push({v, v});
        visit[v][v] = true;
      }

      if (v + cb < 1001 && !visit[v + cb][cb]) {
        q.push({v + cb, cb});
        visit[v + cb][cb] = true;
      }

      if (v > 0 && !visit[v - 1][cb]) {
        q.push({v - 1, cb});
        visit[v - 1][cb] = true;
      }
    }
    ret++;
  }
  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> S;

  cout << bfs() << "\n";

  return 0;
}