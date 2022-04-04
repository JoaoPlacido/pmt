#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include "algorithms.hpp"

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
bool sellers(string txt, string pat, int& count, int err_size) {
    int patlen = pat.length();
    bool find = false;
    vector<int> nxtc(patlen + 1, 0);
    vector<int> col(patlen + 1);
    iota(col.begin(), col.end(), 0);
    for (int i = 0; i < txt.length(); i++) {
        nextC(col, pat, patlen, txt[i], nxtc);
        col = nxtc;
        //cout <<col[1]<< "\n";
        //cout << col[patlen];
        if (col[patlen] <= err_size){
           count++;
           find = true;
        }   
    }
    return find;
}
void run_sellers(vector<string> txt_set, vector<string> pat_set, bool c,int err_size){
    vector<vector<int>> lps_set;
    int l_txt_set = (int)txt_set.size();
    int l_pat_set = (int)pat_set.size();
    vector<int> count (l_pat_set,0);
    for(int i = 0;i<l_txt_set;i++){
        ifstream txt(txt_set[i]);
        string line;
        int n_line = 1;
        while(!txt.eof()){
            getline(txt,line);
            bool find = false;
            for(int j = 0; j<l_pat_set;j++){
                find =sellers(line,pat_set[j],count[j],err_size);
            }
            if(find and !c){
                    cout << "line "<<n_line<<": "<<line<<endl;
            }
            n_line++;
        }
        txt.close();
    }
    if(c){
        for(int i =0;i<l_pat_set;i++){
            cout << pat_set[i]<<": "<<count[i]<<endl;
        }
    }   
}