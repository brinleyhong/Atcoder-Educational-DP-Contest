#include <bits/stdc++.h>
using namespace std;
const int maxn = 400;
typedef long long ll;
const ll INF = LLONG_MAX;
ll dp[maxn+5][maxn+5], prefixsum[maxn+5];
int n, a[maxn+5];
ll dequy(int l, int r)
{
    if (l == r)
        return 0LL;
    if (dp[l][r] != INF)
        return dp[l][r];
    for (int k = l; k<r; ++k)
    {
        dp[l][r] = min(dp[l][r], (ll) dequy(l, k) + dequy(k+1, r) + (ll) prefixsum[r]-prefixsum[l-1]);
    }
    return dp[l][r];
}
void solve()
{
    cin >> n;
    prefixsum[0] = 0;
    for (int i = 1; i<=n; ++i)
    {
        for (int j = 1; j<=n; ++j)
        {
            dp[i][j] = INF;
        }
    }
    for (int i = 1; i<=n; ++i){
        cin >> a[i];
        prefixsum[i] = (ll) prefixsum[i-1] + a[i];
    }
    dequy(1, n);
    cout << dp[1][n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
