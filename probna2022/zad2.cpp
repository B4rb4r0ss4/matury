#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream file; file.open("./Dane_2212/pary.txt");
    int a, b; 
    vector<pair<int, int>> xd;
    while(file>>a>>b) {
        int tmpa = a, tmpb = b;
        while(b >= a) {
            if(b==a) {
                xd.push_back({tmpa, tmpb});
                break;
            }
            else b/=2;
        }     

    } 
    for(auto i: xd) {
        cout<<i.first<<' '<<i.second<<'\n';
    }
}
