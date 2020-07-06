#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int M, N, L;
struct ANIMAL {
  int y, x;
};
vector<int> hunter;
vector<pii> animal;

bool check(const pii& a, const int h) {
  int dist = abs(a.first - h) + a.second;
  if (dist <= L) return true;
  return false;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> M >> N >> L;
  hunter.resize(M);
  animal.resize(N);
  int a, b;
  for (int i = 0; i < M; ++i) {
    cin >> hunter[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    animal[i] = {a, b};
  }

  sort(hunter.begin(), hunter.end());
  sort(animal.begin(), animal.end());
  int ans = 0;
  for (auto ani : animal) {
    auto target = lower_bound(hunter.begin(), hunter.end(), ani.first) - hunter.begin();

    if (check(ani, hunter[target])) {
      ans++;
    } else {
      if (target > 0) {
        --target;
        if (check(ani, hunter[target])) {
          ans++;
        }
      }
    }
  }

  cout << ans << "\n";

  return 0;
}