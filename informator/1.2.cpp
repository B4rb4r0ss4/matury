#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE = 1e6;
int tab[SIZE];
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/dane1_4.txt");
    int n = 100001;
    int maxi = 0; int sum = 0;
    int start = 1; int end = 1;
    pair<int, int> longest;
    for(int i=1; i<=n; i++) {
        file>>tab[i];
        end = i;
        sum+=tab[i];
        maxi = max(maxi, sum);
        if(sum == maxi) longest={start, end};
        if(sum < 0) {
            sum = 0;
            start = i+1;
        }
    }
    cout<<' '<<longest.first<<' '<<longest.second;
    
}
