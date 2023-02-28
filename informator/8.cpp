#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/dane8.txt");
    vector<int> xd;
    int num;
    while(file>>num) {
        xd.push_back(num);
    }
    int ilePa = 0, ileNie = 0;
    for(int i=1; i<xd.size(); i++) {
       int luka = abs(xd[i-1] - xd[i]);
       if(luka&1) ileNie++;
       else ilePa++;

    }
    cout<<ilePa<<' '<<ileNie<<'\n';
    int ans = 0;
    for(int i=0; i<xd.size()-1; i++) {
        for(int j = i+1; j<xd.size(); j++) 
            if(xd[i] > xd[j]) ans++;
    }
    cout<<ans<<'\n';
    int maxi = 1; int ile = 1;
    for(int i=1; i<xd.size(); i++) {
        if(xd[i] > xd[i-1]) ile++;
        else ile = 1;
        maxi = max(ile, maxi);
    }
    cout<<maxi<<'\n';
    int maxii = 1;
    vector<int> dp(xd.size());
    for(int i=0; i<xd.size(); i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++)
            if(xd[i] > xd[j]) dp[i] = max(dp[i], dp[j]+1);
        maxii = max(maxii, dp[i]);
    }
    cout<<maxii;
}
