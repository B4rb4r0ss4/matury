#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/dane3.txt");
    int n = 2023;
    int mini = INT_MAX, maxi=0;
    vector<int> val;
    for(int i=0; i<n; i++) {
        int a, b; file>>a>>b;
        int dlu = b-a+1;
        maxi = max(dlu, maxi);
        mini = min(dlu, mini);
        val.push_back(dlu);
    }
    sort(val.begin(), val.end());
    mini = val[0];
    do {
        maxi = val[1];
    } while(maxi == mini);
    
    cout<<mini<<' '<<maxi;
}
