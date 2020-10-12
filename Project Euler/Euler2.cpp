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
//#define cin fin
#define ll long long
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

vi fib;
int sum;

int main() {
    sum = 0;
    fib.push_back(0);
    fib.push_back(1);

    while (true) {
        int num = fib[fib.size()-1] + fib[fib.size()-2];
        if (num < 4000000) {
            fib.push_back(num);
            if (num % 2 == 0) {
                sum+=num;
            }
        }
        else {
            break;
        }
    }

    for (int i = 0; i < fib.size(); i++) {
        cout << fib[i] << endl;
    }
    cout << "sum: " << sum << endl;

    return 0;
}
