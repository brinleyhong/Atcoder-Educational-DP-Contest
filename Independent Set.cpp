#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
const int mod = 1e9 + 7;
int n;
vector<int> adj[maxn+5];
ll dp[maxn+5][2];
void DFS(int u, int parent)
{
    dp[u][0] = 1;
    dp[u][1] = 1;
    for (int v : adj[u])
    {
        if (v == parent) continue;
        DFS(v, u);

        int s = (dp[v][0] % mod + dp[v][1] % mod) % mod;

        dp[u][0] = ((dp[u][0] % mod) * (s % mod)) % mod;
        dp[u][1] = dp[u][1] * dp[v][0] % mod;
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i<n; ++i)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    ll ans = (dp[1][0] % mod + dp[1][1] % mod)%mod;
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
