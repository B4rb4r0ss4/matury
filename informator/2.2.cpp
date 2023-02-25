#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/dane2_4.txt");
    string line;
    while(file >> line) {
        int dep = 0; bool isOk = true;
        for(auto i: line ) {
            if(i == '[') dep++;
            else dep--;
            if(dep < 0) isOk = false;
        }
        if(!dep && isOk) cout<<"TAK\n";
        else cout<<"NIE\n";
    }
}
