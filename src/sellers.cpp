#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;
//sellers algordom
void nextC(vector<int> col, string pat, int patlen, char let, vector<int>& nxtc) {
    fill(nxtc.begin(), nxtc.end(), 0);
    for (int i = 1; i < patlen + 1; i++) {
        int aux = col[i - 1] + 1;
        if (let == pat[i - 1])
            aux--;
        //cout << col[i] + 1 << nxtc[i - 1] + 1 <<"\n";
        nxtc[i] = min(col[i] + 1, nxtc[i - 1] + 1);
        //cout << nxtc[i]<<aux << "\n";
        nxtc[i] = min(nxtc[i], aux);
        //cout << nxtc[i] << "\n";
    }
}
void sellers(string txt, string pat, vector<int>& result, int err_size) {
    int patlen = pat.length();
    vector<int> nxtc(patlen + 1, 0);
    vector<int> col(patlen + 1);
    iota(col.begin(), col.end(), 0);
    for (int i = 0; i < txt.length(); i++) {
        nextC(col, pat, patlen, txt[i], nxtc);
        col = nxtc;
        //cout <<col[1]<< "\n";
        //cout << col[patlen];
        if (col[patlen] <= err_size)
            result.push_back(i);
    }
}