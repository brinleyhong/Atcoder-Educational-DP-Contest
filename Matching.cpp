#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 21;
const int maxbits = 1<<maxn;
ll dp[maxbits+3];
char c[maxn+5][maxn+5];
int n;
bool checkbit(int i, int j)
{
    return (i&(1<<j));
}
void solve()
{
    cin >> n;
    for (int i = 0; i<n; ++i)
    {
        for (int j = 0; j<n; ++j) cin >> c[i][j];
    }
    dp[0] = 1;
    for (int mask = 0; mask < (1<<n); ++mask)
    {
        int cntbit1 = __builtin_popcount(mask);
        for (int i = 0; i<n; ++i)
        {
            if (checkbit(mask, i) || c[cntbit1][i] == '0') continue;
            int v = 1<<i;
            dp[mask|v] = (dp[mask|v]%mod + dp[mask]%mod)%mod;
        }
    }
    cout << dp[(1<<n)-1]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
