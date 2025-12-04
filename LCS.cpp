#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000;
struct elm
{
    char ends;
    int val;
};
elm dp[maxn+5][maxn+5]; //dp[i][j] la
pair<int, int> trace[maxn+5][maxn+5];
void solve()
{
    string s, t; cin >> s >> t;
    s = " " + s;
    t = " " + t;
    dp[0][0].val = 0;
    dp[0][1].val = 0;
    dp[1][0].val = 0;
    dp[0][0].ends = ' ';
    dp[0][1].ends = ' ';
    dp[1][0].ends = ' ';
    int maxlen = -1;
    int n = s.size(), m = t.size();
    for (int i = 1; i<s.size(); ++i)
    {
        for (int j = 1; j<t.size(); ++j)
        {
            if (s[i] == t[j])
            {
                dp[i][j].val =  dp[i-1][j-1].val + 1;
                trace[i][j] = make_pair(i-1, j-1);
                dp[i][j].ends = s[i];
            }
            else
            {
                pair <int, int> maxx = make_pair(i-1, j);
                if (dp[i][j-1].val > dp[i-1][j].val) maxx = make_pair(i, j-1);
                if (dp[i-1][j-1].val > dp[maxx.first][maxx.second].val)
                {
                    maxx.first = i-1;
                    maxx.second = j-1;
                }
                dp[i][j].val = dp[maxx.first][maxx.second].val;
                dp[i][j].ends = dp[maxx.first][maxx.second].ends;
                trace[i][j] = maxx;
            }
            maxlen = max(maxlen, dp[i][j].val);
        }
    }

    pair<int, int> cur = {1, 1};
    for (int i = 1; i<s.size(); ++i)
    {
        for (int j = 1; j<t.size(); ++j)
        {
            if (dp[i][j].val == maxlen)
            {
                cur = make_pair(i, j);
                break;
            }
        }
    }
    string ans = "";
    int bruh = n;
    while (dp[cur.first][cur.second].val != 0)
    {
        if (bruh == dp[cur.first][cur.second].val)
        {
            cur = trace[cur.first][cur.second];
            continue;
        }
        ans +=  dp[cur.first][cur.second].ends;
        bruh = dp[cur.first][cur.second].val;
        cur = trace[cur.first][cur.second];
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
