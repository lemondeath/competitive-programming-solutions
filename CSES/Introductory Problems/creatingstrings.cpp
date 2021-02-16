// CSES Problem Set - Creating Strings
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

string A;
set<string> S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> A;
    sort(all(A));
    S.insert(A);
    while (next_permutation(all(A))) {
        S.insert(A);
    }
    cout << sz(S) << endl;
    for (set<string>::iterator it = S.begin(); it != S.end(); it++) {
        cout << (*it) << endl;
    }

    return 0;
}
