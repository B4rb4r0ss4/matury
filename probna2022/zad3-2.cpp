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
    int liczba; 
    vector<int> primes;
    int maxi = -1, lo = 1e6;
    int val = 0; int val2 = 0;
    for(int i=2; i<n; i++) if(!isPrime[i])primes.push_back(i);
    while(file>>liczba) {
        int ile = 0;
        for(int i=2; i<liczba/2+1; i++) {
            if(!isPrime[i] && !isPrime[liczba-i]) ile++;
        }

        if(ile > maxi) {
            val = liczba;
            maxi = ile; 
        }
        else if(ile <= lo) {
            val2 = liczba;
            lo = ile;
        }
        
    }
    cout<<maxi<<' '<<val<<'\n';
    cout<<lo<<' '<<val2;
}
