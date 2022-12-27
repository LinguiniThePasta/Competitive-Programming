#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include <iomanip>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#include <cmath>
#include <map>
#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include <iomanip>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include<algorithm>
#include <cassert>
#include <stack>
#include<cstring>
#include <cmath>
#include <complex>
#include <sstream>
#include<cstring>
#include <complex>
#include<cstdlib>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <iterator>
#include <math.h>
#include <cstdio>
#include<map>
using namespace std;
#define ll long long
#include <vector>
#include <iostream>
using namespace std;
#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define fast std::ios_base::sync_with_stdio(false);
using namespace std;

char grid[60][60];
bool visited[60][60];
int M, N;
bool valid(int r, int c) {
    return r >= 0 && c >= 0 && r < M && c < N;
}
bool check(int i, int j) {
    return grid[i][j] == 'I' || grid[i][j] == 'E' || grid[i][j] == 'H' || grid[i][j] == 'O' || grid[i][j] == 'V' || grid[i][j] == 'A' || grid[i][j] == '@' || grid[i][j] == '#';
}
int dirX[3] = {0,1,-1};
int dirY[3] = {-1,0,0};
string dirWord[3] = {"forth", "right", "left"};
vector<string> path(0);

void dfs(int r, int c) {
    if (visited[r][c] || grid[r][c] == '#') {
        return;
    }
    visited[r][c] = true;
    for (int k = 0; k < 3; k++) {
        int dx = c + dirX[k];
        int dy = r + dirY[k];
        string word = dirWord[k];
        if (valid(dy, dx) && !visited[dy][dx] && check(dy,dx)) {
            dfs(dy, dx);
            path.push_back(word);
        }
    }
}
int main() {
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        cin >> M >> N;

        path = {};
        for (int i = 0; i < M; i++) {
            scanf("%s", grid[i]);
        }

        int r,c = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '@') {
                    r = i;
                    c = j;
                    break;
                }
            }
        }
        dfs(r,c);

        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;

    }
}