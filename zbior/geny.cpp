#include <bits/stdc++.h>
using namespace std;
struct gen {
    string genotyp;
    bool slaby = 0;
    vector<string> g, gRev;
    int ile = 0;
    int najd = 0;
    bool silnieOdporny = 0;
    bool odporny = 0;
    void checkOdpornosc() {
        string tmp = genotyp;
        reverse(tmp.begin(), tmp.end());
        silnieOdporny = (tmp == genotyp);
        string trol = "", trol2="";
        for(auto i: g) {
            trol+=i;
        }
        for(auto i: gRev) trol2+=i;
        odporny = (trol == trol2);
    };
    void generateG() {
        string ge = "";
        string reve = genotyp;
        reverse(reve.begin(), reve.end());
        char prev = 'x';
        for(auto i: genotyp) {
            if(i == 'A' && (ge.size()==0 || ge=="A")) ge+=i;
            else if(ge.size()==2 && ge!="AA") ge="";
            else if(ge.size() >= 2) {
                ge+=i;
                if(ge[ge.size()-1] == 'B' && ge[ge.size()-2] == 'B') {
                    g.push_back(ge);
                    int wiel = ge.size();
                    najd = max(wiel, najd);
                    ge = "";
                    ile++;
                }
            } else if(ge.size()==1 && i!='A') ge=""; 
            prev = i;
        }
        ge = "";
        prev = 'x';
        for(auto i: reve) {
            if(i == 'A' && (ge.size()==0 || ge=="A")) ge+=i;
            else if(ge.size()==2 && ge!="AA") ge="";
            else if(ge.size() >= 2) {
                ge+=i;
                if(ge[ge.size()-1] == 'B' && ge[ge.size()-2] == 'B') {
                    gRev.push_back(ge);
                    int wiel = ge.size();
                    najd = max(wiel, najd);
                    ge = "";
                }
            } else if(ge.size()==1 && i!='A') ge=""; 
            prev = i;
        }
    };
    void slabe() {
        string wzorzec = "BCDDC";
        for(auto i: g) {
            string b = wzorzec + "#" + i;
            vector<int> pi(b.size(), -1);
            pi[0] = -1;
            for(int i=1; i<b.size(); i++) {
                pi[i] = pi[i-1];
                while(pi[i] != -1 && b[pi[i]+1] != b[i]) {
                pi[i] = pi[pi[i]];
            }
            if(b[pi[i]+1] == b[i]) pi[i]++;

            if(pi[i] == wzorzec.size()-1) slaby=1;
            }
        }
    };
};

int osobniki[510];

int main() {
    ifstream file; file.open("dane_geny.txt");
    vector<gen> genotypy;
    for(int i=0; i<1000; i++) {
        string a; file>>a;
        gen xd;
        xd.genotyp = a;
        xd.generateG();
        xd.slabe();
        xd.checkOdpornosc();
        genotypy.push_back(xd);
        osobniki[a.size()]++;
    }
    int ileOso = 0, maxi = 0;
    for(int i=1; i<501; i++) {
        if(osobniki[i]) {
            ileOso++;
            maxi = max(osobniki[i], maxi);
        }
    }
    int ileSla = 0, maxi2 = 0, maxi3 = 0, ileSilno =0, ileOdpo=0;
    for(auto i: genotypy) {
        if(i.slaby) {
            ileSla++;
        }
        if(i.silnieOdporny) ileSilno++;
        if(i.odporny) ileOdpo++;
        maxi2 = max(maxi2, i.ile);
        maxi3 = max(maxi3, i.najd);
    }
    cout<<"Ilość gatunków: "<<ileOso<<'\n'
        <<"Najwięcej osobników danego gatunku: "<<maxi<<'\n'
        <<"Ile slabych mutacji: "<<ileSla<<"\n"
        <<"Największa liczba genów:  "<<maxi2<<'\n'
        <<"Największa długość genu: "<<maxi3<<'\n'
        <<"Ilość odpornych: "<<ileOdpo<<'\n'
        <<"Ilość silnie odpornych: "<<ileSilno<<'\n';
}
