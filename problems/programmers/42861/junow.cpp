#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int root[5000];

int find(int i) {
  if (root[i] == i)
    return i;
  return find(root[i]);
}

void merge(int i, int j) {
  root[find(j)] = find(i);
}

struct INFO {
  int from, to, w;
};

struct compare {
  bool operator()(INFO &a, INFO &b) {
    return a.w > b.w;
  }
};

int solution(int n, vector<vector<int>> costs) {
  int answer = 0;
  priority_queue<INFO, vector<INFO>, compare> pq;

  for (int i = 0; i < n; i++) root[i] = i;

  for (auto &cost : costs) {
    int from = cost[0];
    int to = cost[1];
    int w = cost[2];
    pq.push({from, to, w});
  }

  while (!pq.empty()) {
    INFO top = pq.top();
    pq.pop();
    if (find(top.from) == find(top.to)) continue;
    answer += top.w;
    merge(top.from, top.to);
  }
  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 4;
  vvi costs = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};
  int n2 = 4;
  vvi costs2 = {{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4}};
  int n3 = 6;
  vvi costs3 = {{0, 1, 5}, {0, 3, 2}, {0, 4, 3}, {1, 4, 1}, {3, 4, 10}, {1, 2, 2}, {2, 5, 3}, {4, 5, 4}};
  int n4 = 4;
  vvi costs4 = {{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4}};
  int n5 = 5;
  vvi costs5 = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 3}, {2, 3, 8}, {3, 4, 1}};
  int n6 = 5;
  vvi costs6 = {{0, 1, 1}, {3, 4, 1}, {1, 2, 2}, {2, 3, 4}};
  cout << solution(n, costs) << endl;
  cout << solution(n2, costs2) << endl;
  cout << solution(n3, costs3) << endl;
  cout << solution(n4, costs4) << endl;
  cout << solution(n5, costs5) << endl;
  cout << solution(n6, costs6) << endl;
  return 0;
}
