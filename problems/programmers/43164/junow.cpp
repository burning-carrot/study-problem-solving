#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool visit[10001];
int maxSize;

bool isVisit(vector<string>& visit, string s) {
  for (auto& v : visit) {
    if (s == v) return true;
  }
  return false;
}
bool dfs(string from, map<string, vector<string>>& m, vector<string>& course, vector<string>& visit) {
  if (course.size() == maxSize) {
    return true;
  }

  vector<string> toList = m[from];

  for (int i = 0, size = toList.size(); i < size; i++) {
    string s = from + "," + to_string(i);
    string to = toList[i];
    if (isVisit(visit, s)) continue;
    visit.push_back(s);
    course.push_back(to);
    if (dfs(to, m, course, visit)) {
      return true;
    }
    course.pop_back();
    visit.pop_back();
  }

  return false;
}

vector<string> solution(vector<vector<string>> tickets) {
  maxSize = tickets.size() + 1;
  map<string, vector<string>> m;
  for (auto& v : tickets) {
    string from = v[0];
    string to = v[1];
    if (m.find(from) == m.end()) {
      vector<string> vs = {to};
      m[from] = vs;
    } else {
      m[from].push_back(to);
    }
  }

  for (auto& v : m) {
    sort(v.second.begin(), v.second.end());
  }

  string start = "ICN";
  vector<string> course;
  course.push_back(start);
  vector<string> visit;
  dfs(start, m, course, visit);

  return course;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<string>> tickets1 = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
  vector<vector<string>> tickets2 = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
  vector<vector<string>> tickets3 = {{"ICN", "A"}, {"ICN", "B"}, {"B", "ICN"}};

  vector<string> ans = solution(tickets3);
  for (string& v : ans) {
    cout << v << " ";
  }

  return 0;
}