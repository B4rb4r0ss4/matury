#include <bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<int, char> xd;
const int SIZE = 30;
int ile[SIZE];
string decode(string lul) {
    string re = "";
    for(auto i: lul) {
       re+=xd[ile[i-'A']]; 
    }
    return re;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ifstream file; file.open("./DANE/czestosc.txt");
    ifstream file2; file2.open("./DANE/szyfrogram.txt");
    string line; 
    while(file2>>line) {
        for(auto i: line) {
            ile[i-'A']++;
        }
    }
    char a; int key;
    while(file>>a>>key) {
        xd[key] = a;
    }

    file2.close();
    file2.open("./DANE/szyfrogram.txt");
    cout<<decode("CAIMURJH")<<" ZAD 7.1\n";
    while(file2>>line) {
        cout<<decode(line)<<'\n';
    }
}
