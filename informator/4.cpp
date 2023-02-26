#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tab[2023];
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/dane4.txt");
    for(int i=0; i<2023; i++) {
        file>>tab[i];
    }
    int ans = 0, maxi = 0;
    for(int i=1; i<2023; i++) {
        int val = 0;
        for(int j=0; j<i; j++) {
            if(tab[i] > tab[j])
                val++;
        }
        maxi = max(maxi, val);
        if(maxi == val) ans = i;

    }
    ans++;
    cout<<ans;
}
