#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define esp 1e-8
#define lson   l, m, rt<<1
#define rson   m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define pb push_back
#define in freopen("solve_in.txt", "r", stdin);
#define bug(x) printf("Line : %u >>>>>>\n", (x));
#define inf 0x0f0f0f0f
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 10;
char maze[maxn][maxn], vis[maxn][maxn];
int dx[] = {-1, 1, -1, 1};
int dy[] = {1, 1, -1, -1};

int ans;
bool check(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10;
}
void dfs(int x, int y, int t) {
    ans = max(ans, t);
    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(check(nx, ny) == false || check(nx+dx[k], ny+dy[k]) == false)
            continue;
        if(maze[nx+dx[k]][ny+dy[k]] == '#' ||vis[nx+dx[k]][ny+dy[k]])
           ;
        else continue;
        if(maze[nx][ny] != 'B' || vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        dfs(nx+dx[k], ny+dy[k], t+1) ;
        vis[nx][ny] = 0;
    }
}

int main() {
    
    int T;
    for(int t = scanf("%d", &T); t <= T; t++) {
        ans = 0;
        for(int i = 0; i < 10; i++) scanf("%s", maze[i]);
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                if(maze[i][j] == 'W') {
                    memset(vis, 0, sizeof vis);
                    vis[i][j] = 1;
                    dfs(i, j, 0);
                }
        cout << ans << endl;
    }
    return 0;
}
