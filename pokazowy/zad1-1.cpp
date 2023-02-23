#include <bits/stdc++.h>
using namespace std;
#define FILEM szachy.txt
#define FILEE szachy_przyklad.txt

struct plansza {
    char fields[8][8];
};

vector<plansza> plansze;
int main() {
    ifstream file;
    file.open("./Dane_2203/szachy.txt");
    for(int k=0; k<125; k++) {
        plansza cur;
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                file>>cur.fields[i][j];
            }   

        }
        plansze.push_back(cur);
    }
    int ans = 0;
    int maxi = 0;
    for(auto k: plansze) {
        int ile = 0;
        for(int i=0; i<8; i++) {
            bool isEmpty = 1;
            for(int j=0; j<8; j++) {
                if(k.fields[j][i] != '.') isEmpty = false;
            }
            if(isEmpty) ile++;
        }
        if(ile > 0) ans++;
        maxi = max(ile, maxi);
    }
    cout<<ans<<' '<<maxi;
}

