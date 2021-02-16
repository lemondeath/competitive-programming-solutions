// CCC '20 S5 - Josh's Double Bacon Deluxe
// scored 9/15 points
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define MMAX (int)(5e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, A[NMAX], last[MMAX], burgers[MMAX], coach, josh;
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
        if (last[i] == -1) continue;
        if (i == coach) disruptions.PB({0, coach});
        else disruptions.PB({last[i], i});
    }

    sort(all(disruptions));

    dp[0] = 1.;
    int pos = -1;


    for (int i = 0; i + 1 < sz(disruptions); i++) {
        int ipos = disruptions[i][0];
        while (++pos < ipos) {
            burgers[A[pos]]--;
        }

        for (int j = i + 1; j < sz(disruptions); j++) {
            int jburg = disruptions[j][1]; // jth disrupted person's burger
            dp[j] += dp[i] * burgers[jburg] / (N - pos);
        }
        burgers[disruptions[i + 1][1]]--; // check if within array
    }

    cout << setprecision(8) << 1. - dp[sz(disruptions) - 1] << endl;


    return 0;
}
