// CSES Problem Set - Towers
// same as Longest Increasing Subsequence, but now Non-Decreasing
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N;
vi dp;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        int pos = lower_bound(all(dp), x + 1) - dp.begin();
        if (pos == sz(dp)) dp.PB(x);
        else dp[pos] = x;
    }
    cout << sz(dp) << endl;


    return 0;
}
