#include <bits/stdc++.h>
using namespace std;
int alpha[30];
int main() {
    ifstream file; file.open("../dane/instrukcje.txt");
    string pol; char dod;
    string res = "";
    const int N = 2000;
    int ile = 0; char prev = 'h'; int cur; string polec;
    for(int i=0; i<N; i++) {
        file>>pol>>dod;
        if(prev == pol[0]) cur++;
        else cur = 1; 
        prev = pol[0];
        if(ile < cur) {
            ile = cur;
            polec = pol;
        }
        char POL = pol[0];
        if(POL == 'D') { res+=dod;
           alpha[dod-'A']++; 
        }
        else if(POL == 'U') {
            res = res.substr(0, (res.size()-((int)(dod-'0'))));
        }else if(POL == 'Z') res[res.size()-1] = dod;
        else if(POL == 'P') {
            int ind = res.find(dod);
            if(ind != -1)
                res[ind] = res[ind]+1;
            if(res[ind] == 'Z'+1) res[ind] = 'A';
        }
    }
    cout<<res.size()<<'\n';
    cout<<polec<<' '<<ile<<'\n';
    int maxi = 0; char xd;
    for(int i=0; i<29; i++) {
        if(alpha[i] > maxi) {
            maxi = alpha[i];
            xd = i+'A';
        }
    }
    cout<<maxi<<' '<<xd<<'\n';
    cout<<res;   
}
