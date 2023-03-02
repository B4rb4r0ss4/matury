#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE = 1e6;
int ile[SIZE];
struct trojki {
    int a; int b; int c;
}; 
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./Dane_2205/liczby.txt");
    int line; 
    vector<int> xd;
    while(file>>line) {
        xd.push_back(line);
    }
    int ans = 0;
    vector<trojki> xd2;
    for(auto i: xd) {
        for(auto j: xd) {
            for(auto k: xd) {
                if(i!=j && j!=k && i!=k) {
                    if(k%j == 0 && j%i==0) {
                        ans++;
                        trojki waht; waht.a = i; waht.b = j; waht.c = k;
                        xd2.push_back(waht);
                    }
                }
            }
        }

    }
    cout<<ans<<'\n';
    int ans2 = 0;
    for(auto i: xd2) {
        cout<<i.a<<' '<<i.b<<' '<<i.c<<'\n';
        for(auto j: xd) {
            for(auto k: xd) {
                if(j != k && k>j && j>i.c && k%j == 0 && j%i.c == 0) ans2++;
            }
        }
    }
    cout<<ans2;
}
