// CSES Problem Set - List Removals
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(5e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N;
oset S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        S.insert({i, a});
    }
    for (int i = 0; i < N; i++) {
        int x; cin >> x; --x;
        ii ans = *S.find_by_order(x);
        cout << ans[1] << " ";
        S.erase(ans);
    }
    cout << endl;

    return 0;
}
