// USACO 2021 January Contest, Silver
// Problem 3. Spaced Out
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A[NMAX][NMAX];
ll ans;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll odd = 0, even = 0;
        for (int j = 0; j < N; j++) {
            if (j & 1) odd += A[i][j];
            else even += A[i][j];
        }
        sum += max(odd, even);
    }
    ans = sum;
    sum = 0;
    for (int i = 0; i < N; i++) {
        ll odd = 0, even = 0;
        for (int j = 0; j < N; j++) {
            if (j & 1) odd += A[j][i];
            else even += A[j][i];
        }
        sum += max(odd, even);
    }
    ans = max(ans, sum);

    cout << ans << endl;

    return 0;
}
