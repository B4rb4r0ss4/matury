#include<bits/stdc++.h>
using namespace std;
const int SIZE = 10;
vector<string> antyPalindro;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/dane6.txt");
    string line;
    while(file>>line) {
        int sum = 0;
        bool isOk = true;
        int n = line.size()-1;
        for(int i=0; i<n/2; i++) {
            if(line[i] == line[n-i]) isOk = false;
        }
        if(isOk) antyPalindro.push_back(line);
    }

    for(auto i: antyPalindro) {
        cout<<i<<'\n';

    }
    cout<<antyPalindro.size();
}
