#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

ll L[MAXN],R[MAXN];

int main() {
    FastIO;
    string s;
    cin >> s;
    ll ans = 1;
    L[0] = 1;
    R[s.size() - 1] = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            L[i] = L[i - 1] + 1;
        } else {
            L[i] = 1;
        }
        ans += L[i];
    }
    for (int i = s.size() - 2; i >= 0; i--) {
        if (s[i] == s[i + 1]) {
            R[i] = R[i + 1] + 1;
        } else {
            R[i] = 1;
        }
    }
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i - 1] == s[i + 1] && s[i - 1] != s[i]) {
            ans += min(L[i - 1], R[i + 1]);
        }
    }
    cout << ans;
    return 0;
}