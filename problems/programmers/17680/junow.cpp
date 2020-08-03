#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

string toLower(string s) {
  string ret = "";
  for (auto& v : s) ret += tolower(v);
  return ret;
}

bool checkCache(priority_queue<pair<int, string>> cache, string& city) {
  while (!cache.empty()) {
    auto cur = cache.top();
    cache.pop();
    if (cur.second == city) return true;
  }

  return false;
}

priority_queue<pair<int, string>> updateCache(priority_queue<pair<int, string>>& cache, string& city, int time) {
  priority_queue<pair<int, string>> ret;

  while (!cache.empty()) {
    auto cur = cache.top();
    cache.pop();
    if (cur.second == city) {
      ret.push({-time, city});
    } else {
      ret.push(cur);
    }
  }

  return ret;
}

int solution(int cacheSize, vector<string> cities) {
  int answer = 0;
  priority_queue<pair<int, string>> cache;
  for (auto& v : cities) v = toLower(v);

  for (int i = 0, size = cities.size(); i < size; i++) {
    if (checkCache(cache, cities[i])) {
      answer++;
      cache = updateCache(cache, cities[i], i);
    } else {
      if (!cache.empty() && cache.size() >= cacheSize) cache.pop();
      if (cache.size() < cacheSize) cache.push({-i, cities[i]});
      answer += 5;
    }
  }

  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cacheSize1 = 3;
  vector<string> cities1 = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
  int cacheSize2 = 3;
  vector<string> cities2 = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
  int cacheSize3 = 2;
  vector<string> cities3 = {"Jeju", "Pangyo", "NewYork", "newyork"};
  cout << solution(cacheSize2, cities2) << endl;

  return 0;
}