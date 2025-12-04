#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
const ll INF = LLONG_MAX;
ll h[maxn+5], ans[maxn+5];
bool vis[maxn+5];
int n, k;
void dequy(int i)
{
    if (i <= 1) return;
    if (vis[i]) return;
    for (int t = 1; t<=k; ++t)
    {
        if (i-t < 1) break;
        dequy(i-t);
        ans[i] = min(ans[i], abs(h[i] - h[i-t]) + ans[i-t]);
    }
    vis[i] = true;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        ans[i] = INF;
    }
    ans[1] = 0;
    vis[1] = true;
    dequy(n);
    cout << ans[n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
