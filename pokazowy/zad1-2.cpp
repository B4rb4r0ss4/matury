#include <bits/stdc++.h>
using namespace std;
int ileBierek = 80;
struct plansza {
    char fields[8][8];
    int ileFigurBia[6];
    int ileFigurCza[6];
    bool rowno = 1;
    void Rownowaga() {
        bool isOk = 1;
        int liczbaBierek = 0;
        for(int i=0; i<6; i++) {
            if(ileFigurBia[i] != ileFigurCza[i]) isOk = 0;
            if(ileFigurBia[i] > 0) liczbaBierek+=ileFigurBia[i];
        }
        rowno = isOk;
        if(rowno) ileBierek = min(ileBierek, liczbaBierek);
    };
};

vector<plansza> plansze;
int main() {
    ifstream file;
    file.open("./Dane_2203/szachy.txt");
    for(int k=0; k<125; k++) {
        plansza cur;
        for(int i=0; i<6; i++) {
            cur.ileFigurBia[i] = 0;
            cur.ileFigurCza[i] = 0;
        }
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                file>>cur.fields[i][j];
                // pionek 0, skoczek 1, goniec 2, wieza 3, krol 4, dama 5
                if(cur.fields[i][j] == 'k') cur.ileFigurBia[4]++;
                if(cur.fields[i][j] == 's') cur.ileFigurBia[1]++;
                if(cur.fields[i][j] == 'g') cur.ileFigurBia[2]++;
                if(cur.fields[i][j] == 'h') cur.ileFigurBia[5]++;
                if(cur.fields[i][j] == 'p') cur.ileFigurBia[0]++;
                if(cur.fields[i][j] == 'w') cur.ileFigurBia[3]++;
                
                if(cur.fields[i][j] == 'K') cur.ileFigurCza[4]++;
                if(cur.fields[i][j] == 'S') cur.ileFigurCza[1]++;
                if(cur.fields[i][j] == 'G') cur.ileFigurCza[2]++;
                if(cur.fields[i][j] == 'H') cur.ileFigurCza[5]++;
                if(cur.fields[i][j] == 'P') cur.ileFigurCza[0]++;
                if(cur.fields[i][j] == 'W') cur.ileFigurCza[3]++;

            }   

        }
        cur.Rownowaga();
        plansze.push_back(cur);
        
    }
    int ans = 0;

    for(auto k: plansze) {
       if(k.rowno) ans++; 
        
    }
    cout<<ans<<' '<<ileBierek*2;
}

