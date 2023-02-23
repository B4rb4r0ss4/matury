#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pot(ll a, ll b, ll MOD) {
    if(b == 0) return 1%MOD;
    if(b & 1) return (a * pot(a, b-1, MOD))%MOD;
    ll res = pot(a, b/2, MOD);
    return (res*res)%MOD;
}

int main() {
    ll n, k, MOD; cin>>n>>k>>MOD;
    cout<<pot(n, k, MOD);
}
