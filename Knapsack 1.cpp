#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2;
const int maxw = 1e5;
int n, W;
ll dp[maxw+5];
struct elm
{
    int v, w;
}items[maxn+5];
void solve()
{
    cin >> n >> W;
    for (int i = 1; i<=n; ++i) cin >> items[i].w >> items[i].v;
    ll ans = -1;
    dp[0] = 0;
    for (int i=1; i<=n; ++i)
    {
        for (int s = W; s>=items[i].w; --s)
        {
            dp[s] = (ll) max(dp[s], (ll) dp[s-items[i].w] + items[i].v);
        }
    }
    for (int s = 1; s<=W; ++s) ans = max(ans, dp[s]);
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
