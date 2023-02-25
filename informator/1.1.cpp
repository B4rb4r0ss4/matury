#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE = 1e6;
int tab[SIZE];
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/dane1_3.txt");
    int n = 1000;
    int maxi = 0; int sum = 0;
    for(int i=0; i<n; i++) {
        file>>tab[i];
        sum+=tab[i];
        maxi = max(maxi, sum);
        if(sum < 0) {
            sum = 0;
        }
    }
    cout<<maxi;
    
}
