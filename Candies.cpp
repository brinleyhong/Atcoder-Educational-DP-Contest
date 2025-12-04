#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int maxk = 1e5;
const int mod = 1e9 + 7;
typedef long long ll;
int n, k, a[maxn+5];
ll dp[maxn+5][maxk+5], prefixsum[maxn+5][maxk+5];
void solve()
{
    cin >> n >> k;
    for (int i = 0; i<=n; ++i)
    {
        for (int j = 0; j<=k; ++j)
        {
            dp[i][j] = 0LL;
        }
    }
    for (int i = 1; i<=n; ++i) cin >> a[i];
    for (int i = 0; i<=n; ++i)
    {
        dp[i][0] = 1LL;
        prefixsum[i][0] = 1LL;
    }
    for (int i = 1; i<=n; ++i)
    {
        for (int sum = 1; sum<=k; ++sum)
            prefixsum[i-1][sum] = (prefixsum[i-1][sum-1]%mod + dp[i-1][sum]%mod)%mod;
        for (int sum = 1; sum<=k; ++sum)
        {

            int v = sum - a[i] - 1;
            if (v < 0) dp[i][sum] = prefixsum[i-1][sum];
            else dp[i][sum] = (prefixsum[i-1][sum] - prefixsum[i-1][v] + mod)%mod;
        }
    }
    cout << dp[n][k]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
