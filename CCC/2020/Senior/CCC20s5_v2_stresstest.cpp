// CCC '20 S5 - Josh's Double Bacon Deluxe
// stress test for backwards version
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define MMAX (int)(5e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, A[NMAX], last[MMAX], burgers[MMAX], burgcount[MMAX], coach, josh, dporder[MMAX];
vii disruptions;
double dp[MMAX];

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(burgers, -1, sizeof(burgers));
    memset(last, -1, sizeof(last));
    cin >> N;
    for (int i = 0; i < N; i++) {
        int burg; cin >> burg;
        A[i] = burg;
        last[burg] = i;
        if (burgers[burg] == -1) burgers[burg] = 0;
        burgers[burg]++;
        M = max(M, burg);
    }

    coach = A[0];
    josh = A[N - 1];

    if (coach == josh) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i <= M; i++) {
        if (last[i] == -1 || i == josh || i == coach) continue;
        disruptions.PB({last[i], i});
    }
    sort(all(disruptions));
    reverse(all(disruptions));
    for (int i = 0; i < sz(disruptions); i++) {
        dporder[disruptions[i][1]] = i + 1;
    }

    int j = N - 2;
    burgcount[coach] = burgcount[josh] = 1;
    for (int i = 0; i < sz(disruptions); i++) {
        while (j > disruptions[i][0]) {
            burgcount[A[j]]++;
            j--;
        }
        for (int k = 1; k <= i; k++) {
            dp[i + 1] += dp[k] * burgcount[disruptions[k - 1][1]];
        }
        dp[i + 1] += burgcount[coach];
        dp[i + 1] /= (N - j);
    }

    for (int i = 1; i <= sz(disruptions); i++) {
        cout << i << " " << setprecision(12) << disruptions[i - 1][1] << " " << dp[i] << endl;
    }

    double ans = burgers[coach];
    for (int i = 0; i < sz(disruptions); i++) {
        ans += dp[i + 1] * burgers[disruptions[i][1]];
    }
    ans /= N;

    cout << setprecision(8) << ans << endl;

    return 0;
}
