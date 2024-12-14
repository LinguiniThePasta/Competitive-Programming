#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <vector>

#define ll long long
using namespace std;

int grid[182][182];
int ans[182][182];
int recurse(int x, int y, int n, int m) {
  if (grid[x][y] == 1) {
    return 0;
  }
  if (ans[x][y] >= 0) {
    return ans[x][y];
  }
  if (ans[x][y] == -1) {
    return INT_MAX;
  }

  int dx[3] = {-1, 0, 1};
  int dy[3] = {-1, 0, 1};
  int res = INT_MAX;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (dx[i] == 0 && dx[i] == dy[j]) {
        continue;
      }
      if (x + dx[i] < n && y + dy[j] < m && x + dx[i] >= 0 && y + dy[j] >= 0) {
        res = min(res, recurse(x + dx[i], y + dy[j], n, m) + 1);
      }
    }
  }
  ans[x][y] = res;
  return res;
}


int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(ans, -1, sizeof(ans));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
  }
}
