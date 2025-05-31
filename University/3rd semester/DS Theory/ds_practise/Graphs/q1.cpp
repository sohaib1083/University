#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> adj[N];
bool vis[N];

int dfs(int u, int p) {
  vis[u] = true;
  int res = 0;
  for (int v : adj[u]) {
    if (v == p) continue;
    if (vis[v]) {
      // Found a cycle, return 1
      return 1;
    }
    res += dfs(v, u);
  }
  return res;
}

int main() {
  cin >> n;

  // Read in the array and create the graph
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  // Count the number of cycles in the graph
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      ans += dfs(i, -1);
    }
  }

  // The minimum number of swaps is equal to the number of cycles minus 1
  cout << ans - 1 << endl;

  return 0;
}
