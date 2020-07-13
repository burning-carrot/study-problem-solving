#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
vi a(3);
bool visit[201][201][201];
bool ans[201];

void bfs() {
  queue<vi> q;

  vi init(3);
  init[0] = 0;
  init[1] = 0;
  init[2] = a[2];

  q.push(init);
  visit[0][0][a[2]] = true;

  while (!q.empty()) {
    vi cur = q.front();
    q.pop();

    if (cur[0] == 0) {
      ans[cur[2]] = true;
    }

    for (int i = 0; i < 3; i++) {
      if (cur[i] == 0) continue;

      for (int j = 0; j < 3; j++) {
        if (i == j) continue;
        if (cur[j] >= a[j]) continue;  // 할당량 초과
        vi next;
        next.resize(3, 0);
        for (int k = 0; k < 3; k++) {
          next[k] = cur[k];
        }
        int diff = min(next[i], a[j] - next[j]);
        next[i] -= diff;
        next[j] += diff;

        if (visit[next[0]][next[1]][next[2]]) continue;
        q.push(next);
        visit[next[0]][next[1]][next[2]] = true;
      }
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a[0] >> a[1] >> a[2];

  bfs();

  for (int i = 0; i < 201; i++) {
    if (ans[i]) cout << i << " ";
  }
  cout << "\n";

  return 0;
}