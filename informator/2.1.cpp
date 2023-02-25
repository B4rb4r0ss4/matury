#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/dane2_3.txt");
    string line;
    while(file>>line) {
        int dep = 0;
        int maxi = 0;
        for(auto i: line) {
            if(i == '[') dep++;
            else dep--;
            maxi = max(maxi, dep);
        }
        cout<<maxi<<'\n';

    }

}
