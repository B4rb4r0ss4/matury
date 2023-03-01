#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream file; file.open("./Dane_2212/mecz.txt");
    string mecz; file>>mecz;
    int ans;
    for(int i = 1; i<mecz.size(); i++) {
        if(mecz[i] != mecz[i-1]) ans++;
    }
    cout<<ans; 
}
