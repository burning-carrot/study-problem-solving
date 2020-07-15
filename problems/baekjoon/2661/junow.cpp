#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N;
vi seq;

bool isEqual(int _i, int s1, int s2) {
  for (int i = 0; i < _i; i++) {
    if (seq[s1 + i] != seq[s2 + i]) {
      return false;  // it is different;
    }
  }
  return true;
}

bool check(int size) {
  int cnt = 0;
  for (int i = 1; i <= size / 2; i++) {
    int s1 = size - i * 2;
    int s2 = size - i;
    if (isEqual(i, s1, s2)) {
      return false;
    }
  }
  return true;
}

void dfs(int size) {
  if (!check(size)) {
    return;
  }

  if (size == N) {
    for (int i = 0; i < N; i++) {
      cout << seq[i];
    }
    exit(0);
  }

  for (int i = 1; i < 4; i++) {
    seq[size] = i;
    dfs(size + 1);
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;

  seq.resize(N + 1);

  dfs(0);

  return 0;
}

