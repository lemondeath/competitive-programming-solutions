// DMOPC '20 Contest 1 P2 - Victor's Moral Dilemma
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, D, A[NMAX], L, R;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> D;
    L = 1, R = N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += A[i-1];
    }
    for (int i = 0; i < D; i++) {
        int p;
        cin >> p;
        p += L; --p;
        int f = A[p] - A[L-1], s = A[R] - A[p];
        if (f >= s) {
            cout << f << endl;
            L = p + 1;
        }
        else {
            cout << s << endl;
            R = p;
        }
    }

    return 0;
}
