#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./Dane_2205/liczby.txt");
    string line; 
    int ans = 0; string liczba;
    while(file>>line) {
        if(line[0] == line[line.size()-1]) {
            ans++;
            if(ans == 1) liczba = line;
        }
    }
    cout<<ans<<' '<<liczba;
}
