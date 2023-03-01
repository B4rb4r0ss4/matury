#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream file; file.open("./Dane_2212/mecz.txt");
    string mecz; file>>mecz;
    
    int curPassa = 0;
    int curPassId = -1;
    int passa[2] = {0, 0};
    int maxPassaA = 0;
    int maxPassaB = 0;
    int ile = 0;
    for(int i=0; i<mecz.size(); i++) {
        if(mecz[i]-'A' == curPassId) passa[curPassId]++;
        else if(mecz[i] == 'A') {
            maxPassaB = max(maxPassaB, passa[1]);
            if(passa[1] >= 10) ile++;
            passa[1] = 0;
            passa[0] = 1;
            curPassId = 0;
        } else if(mecz[i] == 'B') {
            maxPassaA = max(maxPassaA, passa[0]);
            passa[1] = 1;
            curPassId = 1;
            if(passa[0] >= 10) ile++;
            passa[0] = 0;
        }
    }
    bool ktora = (maxPassaA < maxPassaB);
    char xd[2] = {'A', 'B'};
    cout<<ile<<' '<<xd[ktora]<<' '<<max(maxPassaA, maxPassaB);
}
