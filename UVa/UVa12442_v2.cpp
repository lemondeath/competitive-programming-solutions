// Now I am become Death, the destroyer of worlds.
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <complex>
#include <climits>
#include <fstream>
using namespace std;
//#define cout fout
#define cin fin
#define ll long long
#define NMAX 50003
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

int T, N, u, v;
int AL[NMAX];
int indegree[NMAX];
int ans, maxlen;
bool discovered[NMAX];
bool FLAG;

int dfs(int x) {
    //cout << "DFS STARTING AT " << x << endl;
    bool found[NMAX];
    discovered[x] = true;
    memset(found, 0, sizeof(found));
    int length = 1;
    while (!found[AL[x]]) {
        length++;
        found[AL[x]] = true;
        discovered[AL[x]] = true;
        x = AL[x];
        //cout << x << endl;
    }
    return length;
}

int main() {

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        maxlen = ans = 0;
        memset(AL, 0, sizeof(AL));
        memset(indegree, 0, sizeof(indegree));
        memset(discovered, 0, sizeof(discovered));
        FLAG = false;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> u >> v;
            AL[u] = v;
            indegree[v]++;
        }
        for (int i = 1; i <= 2*N; i++) { // cycle with paths coming in
            int q;
            if (i <= N) {
                q = i;
            }
            else {
                q = i-N;
            }
            if((i <= N && indegree[q] == 0) || (i > N && !discovered[q])) {
                int l = dfs(q);
                if (l > maxlen) {
                    maxlen = l;
                    ans = q;
                }
            }
        }


        cout << "Case " << tc << ": " << ans << endl;

    }

    return 0;
}
