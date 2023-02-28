#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int A = 27;
int alph[A];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/szyfrogram.txt");
    string line;
    while(file>>line) {
        for(auto i: line) alph[i-'A']++;
    }
    for(int i=0; i<A-1; i++) {
        cout<<(char)(i+'A')<<' '<<alph[i]<<'\n';
    }
}
