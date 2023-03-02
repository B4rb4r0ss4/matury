#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE = 1e6;
int isPrime[SIZE];
void sito() {
    isPrime[1] = 1; 
    for(int i = 2; i*i<SIZE; i++) {
        if(!isPrime[i]) {
            for(int j = i*i; j<SIZE; j+=i) if(!isPrime[j]) isPrime[j] = i;
        }
    }
    for(int i=1; i<SIZE; i++) if(!isPrime[i]) isPrime[i] = i;
}

pair<int, int> znajdz(int liczba) {
    vector<int> factor;
    set<int> uniqueFactor;
    do {
        factor.push_back(isPrime[liczba]);
        uniqueFactor.insert(isPrime[liczba]);
        liczba/=isPrime[liczba];
    } while(isPrime[liczba] != 1); 
    return {factor.size(), uniqueFactor.size()};
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./Dane_2205/liczby.txt");
    int line; 
    sito();
    int ans1 = 0, ans2 = 0, liczba1, liczba2;
    while(file>>line) {
        pair<int, int> an = znajdz(line);
        if(an.first > ans1) {
            ans1 = an.first;
            liczba1 = line;
        }
        if(an.second > ans2) {
            ans2 = an.second;
            liczba2 = line;
        }
    }
    cout<<liczba1<<' '<<ans1<<' '<<liczba2<<' '<<ans2;
}
