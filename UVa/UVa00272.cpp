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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

bool insingle, indouble;
string l;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    insingle = indouble = false;
    while (getline(cin, l), !cin.eof()) {
        for (int i = 0; i < l.size(); i++) {
            if (l.at(i) == '"') {
                if (indouble) {
                    cout << "''";
                }
                else {
                    cout << "``";
                }
                indouble = !indouble;
            }
            else {
                cout << l.at(i);
            }
        }
        cout << '\n';
    }

    return 0;
}
