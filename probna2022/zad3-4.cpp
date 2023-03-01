#include<bits/stdc++.h>
using namespace std;
int ile[100];

int main() {
    ifstream file; file.open("./Dane_2212/liczby.txt");
    int liczba;
    while(file>>liczba) {
        stringstream hexi;
        hexi<<hex<<liczba;
        string lul = hexi.str();
        for(auto i: lul) {
            if((int)(i-'a')>=0) {
                int index = i-'a'+10;
                ile[index]++;
            }
            else {
                int index = i-'0';
                ile[index]++;
            }
        }
    }
    for(int i=0; i<10; i++) cout<<i<<": "<<ile[i]<<'\n';

    for(int i='A'; i<='F'; i++) {
        cout<<char(i)<<": "<<ile[i-'A'+10]<<'\n';
    }
}
