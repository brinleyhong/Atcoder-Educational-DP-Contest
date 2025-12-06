#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll) INT_MAX;
const int maxn = 1e2;
const int maxv = 1e5;
ll dp[maxv+5];
int n, W;
struct elm
{
    int w, v;
}items[maxn+5];
void solve()
{
    cin >> n >> W;
    for (int i=1; i<=maxv; ++i) dp[i] = INF;
    for (int i = 1; i<=n; ++i) {
        cin >> items[i].w >> items[i].v;
    }
    dp[0] = 0;
    for (int i = 1; i<=n; ++i)
    {
        for (int j = maxv; j >= items[i].v; --j)
        {
            dp[j] = min(dp[j], (ll) dp[j-items[i].v] + items[i].w);
        }
    }
    int ans = 0;
    for (int i = 1; i<=maxv; ++i)
    {
        if (dp[i] <= W) ans = max(ans, i);
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
