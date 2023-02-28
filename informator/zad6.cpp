#include<bits/stdc++.h>
using namespace std;
const int SIZE = 10;
int liczbyPmin[SIZE];
int sumy[SIZE];
string liczby[SIZE];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/dane6.txt");
    string line;
    while(file>>line) {
        int maxi = 1;
        vector<int> xd(10, 0);
        int sum = 0;
        for(auto i: line) {
            xd[i-'0']++;
            maxi = max((i-'0'), maxi);
            sum+=(i-'0');
        }
        if(xd[maxi-'0'] - 1) {
        liczbyPmin[maxi+1]++;
        sumy[maxi+1] = max(sumy[maxi+1], sum);
        if(sumy[maxi+1] == sum) liczby[maxi+1] = line;
        }
    }
    for(int i=2; i<=10; i++) {
        cout<<i<<'\n'<<liczbyPmin[i]<<'\n';
        cout<<liczby[i]<<'\n';
    }

}
