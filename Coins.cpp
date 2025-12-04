#include <bits/stdc++.h>
using namespace std;
const int maxn = 2999;
typedef double db;
db p[maxn+5], dp[maxn+5][maxn+5];
int n;
void solve()
{
    cin >> n;
    for (int i = 1; i<=n; ++i) cin >> p[i];

    dp[1][0] = (db) 1-p[1];
    dp[1][1] = p[1];
    for (int i = 2; i<=n; ++i) dp[i][0] = dp[i-1][0] * (db) (1-p[i]);

    for (int i = 2; i<=n; ++i)
    {
        for (int j = 1; j<=i; ++j)
        {
            dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (db)(1-p[i]);
        }
    }
    db ans = 0;
    int k = n/2 + 1;
    for (int i = k; i<=n; ++i) ans += dp[n][i];
    cout << fixed << setprecision(10) << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
