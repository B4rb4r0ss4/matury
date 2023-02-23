#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e6;
bool isPrime[SIZE];

void sito() {
    for(int i=2; i*i<SIZE; i++) {
        if(!isPrime[i]) {
            for(int j=i*i; j<SIZE; j+=i) 
                isPrime[j] = 1;
        } 
    }

}

int main() {
    ifstream file; file.open("./Dane_2203/liczby.txt");
    int zlicz = 0, zlicz2 = 0;
    sito();
    for(int i=0; i<1000; i++) {
        int m, a, b; file>>m>>a>>b;
        if(!isPrime[m]) zlicz++;
        if(__gcd(a, m) == 1) zlicz2++;
    }
    cout<<zlicz<<' '<<zlicz2;

}
