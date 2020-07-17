#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int n, m, w[30], a[7];
bool visit[31][150001];

void bt(int cnt, int sum) {
  if (cnt > n) return;
  if (visit[cnt][sum]) return;
  visit[cnt][sum] = true;
  bt(cnt + 1, sum + w[cnt]);
  bt(cnt + 1, sum);
  bt(cnt + 1, abs(sum - w[cnt]));
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> w[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> a[i];
  bt(0, 0);

  for (int i = 0; i < m; i++) {
    if (a[i] > 15000)
      cout << "N ";
    else if (visit[n][a[i]])
      cout << "Y ";
    else
      cout << "N ";
  }

  return 0;
}