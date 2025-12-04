#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
int n, a[maxn+5], b[maxn+5], c[maxn+5];
ll dp[maxn+5][3];
void solve()
{
    cin >> n;
    for (int i = 1; i<=n; ++i) cin >> a[i] >> b[i] >> c[i];

    dp[1][0] = dp[1][1] = dp[1][2] = 0LL;
    ll ans = (ll) -1;
    for (int i = 1; i<=n; ++i)
    {
        dp[i][0] = (ll) max((ll) dp[i-1][1] + a[i], (ll) dp[i-1][2] + a[i]);
        dp[i][1] = (ll) max((ll) dp[i-1][0] + b[i], (ll) dp[i-1][2] + b[i]);
        dp[i][2] = (ll) max((ll) dp[i-1][0] + c[i], (ll) dp[i-1][1] + c[i]);
        ans = (ll) max(ans, (ll) max(dp[i][0], (ll) max(dp[i][1], dp[i][2])));
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
