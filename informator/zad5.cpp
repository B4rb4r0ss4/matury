#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> tab = {10, 9, 8, 7,6, 5, 4, 3, 2, 1};
void W(int x, int ktore) {
    if(x>=1) {
        if(tab[x] < tab[x-1]) {
            int v = tab[x];
            tab[x] = tab[x-1];
            tab[x-1] = v;
            W(x-1, ktore+1);
        }
    }
}
void S1() {
    for(int i=1; i<=10; i++) W(i, 0);
}

void S2() {
    for(int i=9; i>=0; i--) W(i, 0);
}



int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    //ifstream file; file.open();
    int x = 9;
    S1();
    for(auto i: tab) cout<<i<<' ';
     /*
     W(6, 0);
     for(int i=0; i<10; i++) cout<<tab[i]<<' ';
     W(8, 0);
     cout<<'\n';
     for(int i=0; i<10; i++) cout<<tab[i]<<' ';
    */
}
