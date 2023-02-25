#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE = 1e5;
int dlugosci[SIZE];
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/dane3.txt");
    int n = 2023;
    for(int i=0; i<n; i++) {
        int a, b; file>>a>>b;
        int dlu = b-a+1;
        dlugosci[dlu]++;
    }
    int maxi = 0, val;
    for(int i=1; i<1e5; i++) {
        if(dlugosci[i] >= maxi) {
            maxi = dlugosci[i];
            val = i;
        }
    }
    cout<<maxi<<' '<<val;
}
