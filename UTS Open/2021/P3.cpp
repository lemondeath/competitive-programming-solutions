// UTS Open '21 P3 - Latin Class
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
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, cur = 0, ans = 1;
vi A;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        if (x >= cur) {
            cur = x;
            A.PB(i);
        }
    }

    for (int i = 1; i < sz(A); i++) {
        ans *= (A[i] - A[i - 1] + 1);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
