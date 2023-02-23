#include <bits/stdc++.h>
using namespace std;
#define FILEM szachy.txt
#define FILEE szachy_przyklad.txt

struct plansza {
    char fields[8][8];
    bool czarnaSzach = 0;
    bool bialaSzach = 0;
    pair<int, int> pozycjaBialegoKrola;
    pair<int, int> pozycjaCzarngeoKrola;
    void isCheck() {
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                if(fields[i][j] == 'w') {
                    for(int z = i+1; z<8; z++) {
                        if(fields[z][j] == 'K') czarnaSzach = 1;
                        if(fields[z][j] != '.') break;
                    }
                    for(int z = j+1; z<8; z++) {
                        if(fields[i][z] == 'K') czarnaSzach = 1;
                        if(fields[i][z] != '.') break;
                    }
                    for(int z = i-1; z>=0; z--) {
                        if(fields[z][j] == 'K') czarnaSzach = 1;
                        if(fields[z][j] != '.') break;
                    }
                    for(int z = j-1; z>=0; z--) {
                        if(fields[i][z] == 'K') czarnaSzach = 1;
                        if(fields[i][z] != '.') break;
                    } 

                }
                if(fields[i][j] == 'W') {
                    for(int z = i+1; z<8; z++) {
                        if(fields[z][j] == 'k') bialaSzach = 1;
                        if(fields[z][j] != '.') break;
                    }
                    for(int z = j+1; z<8; z++) {
                        if(fields[i][z] == 'k') bialaSzach = 1;
                        if(fields[i][z] != '.') break;
                    }
                    for(int z = i-1; z>=0; z--) {
                        if(fields[z][j] == 'k') bialaSzach = 1;
                        if(fields[z][j] != '.') break;
                    }
                    for(int z = j-1; z>=0; z--) {
                        if(fields[i][z] == 'k') bialaSzach = 1;
                        if(fields[i][z] != '.') break;
                    }

                }

            }
        }
        
    };
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
        cur.isCheck();
        plansze.push_back(cur);
    }
    int szach1=0, szach2=0;
    for(auto k: plansze) {
        if(k.bialaSzach) szach1++;
        if(k.czarnaSzach) szach2++;
    }
    cout<<szach1<<' '<<szach2;
}

