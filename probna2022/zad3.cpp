#include<bits/stdc++.h>
using namespace std;
const int n = 1e6;
bool isPrime[n];
void sito() {
    for(int i=2; i*i<n; i++) {
        if(!isPrime[i]) {
            for(int j = i*i; j<=n; j+=i) isPrime[j] = 1;
        }
    }

}

int main() {
    ifstream file; file.open("./Dane_2212/liczby.txt");
    sito();
    int liczba; int ile = 0;
    while(file>>liczba) {
        
        if(!isPrime[liczba-1]) ile++;
    }
    cout<<ile;
}
