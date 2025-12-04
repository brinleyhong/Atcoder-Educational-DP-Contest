#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nl "\n"
#define sp " "
const int maxn = 1e5;
const int maxm = 1e5;
int par[maxn+5], n, m, dp[maxn+5];
bool vis[maxn+5];
vector <int> adj[maxn+5];
void DFS(int u)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v]) DFS(v);
        dp[u] = max(dp[u], dp[v]+1);
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i<=n; ++i) {par[i] = i; dp[i] = 0;}
    for (int i = 1; i<=m; ++i)
    {
        int u, v; cin >> u >> v;
        par[v] = u;
        adj[u].pb(v);
    }
    for (int i = 1; i<=n; ++i)
    {
        if (par[i] == i) DFS(i);
    }
    int ans = -1;
    for (int i = 1; i<=n; ++i)
        ans = max(ans, dp[i]);
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
