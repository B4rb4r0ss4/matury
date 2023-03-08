#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e6+10;
bool isExpo[SIZE];

void isThree() {
    for(int i=3; i<=SIZE; i*=3) {
        isExpo[i] = 1;
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("../Dane/liczby.txt");
    const int N = 500;
    isThree();
    int ans = 0;
    for(int i=0; i<N; i++) {
        int liczba; file>>liczba;
        if(isExpo[liczba]) ans++;
    }
    cout<<ans;
}
