#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream file; file.open("./Dane_2212/mecz.txt");
    string mecz; file>>mecz;
    int ansA = 0, ansB = 0;
    int i = 0;
    while(true) {
        if(mecz[i] == 'A') ansA++;  
        else ansB++;
        if(abs(ansA - ansB) >= 3 && (ansA >= 1000 || ansB >= 1000 ) && i<mecz.size()) break;
        i++; 
    } 
    if(ansA>ansB) cout<<"A: ";
    else cout<<"B: ";
    cout<<ansA<<' '<<ansB; 
}
