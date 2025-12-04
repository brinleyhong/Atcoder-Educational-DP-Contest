#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1000;
int h, w;
char grid[maxn+5][maxn+5];
ll dp[maxn+5][maxn+5];
int dx[2] = {1, 0};
int dy[2] = {0, 1}; //phai xuong
bool valid(int x, int y)
{
    return (x>=1 && y>=1 && x<=h && y<=w && grid[x][y] == '.');
}
void solve()
{
    cin >> h >> w;
    for (int i = 1; i<=h; ++i)
    {
        for (int j = 1; j<=w; ++j) cin >> grid[i][j];
    }
    dp[1][1] = 1;
    for (int i = 1; i<=h; ++i)
    {
        for (int j = 1; j<=w; ++j)
        {
            if (!valid(i, j)) continue;
            for (int k = 0; k<2; ++k)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (valid(nx, ny))
                {
                    dp[nx][ny] = (ll) ((dp[nx][ny]%mod) + (dp[i][j]%mod))%mod;
//                    cout << "x: " << i << " y: " << j << " nx: " << nx << " ny: " << ny << endl;
                }
            }
        }
    }
    cout << dp[h][w];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
