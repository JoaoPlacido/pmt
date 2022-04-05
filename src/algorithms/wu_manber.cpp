#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithms.hpp>
#include <fstream>
using namespace std;
vector<long> pm(string pat) {
    vector<long> mask(256);
    for (int i = 0; i < 256; i++) {
        mask[i] = ~0;
    }
    for (int i = 0; i < pat.length(); i++) {
        mask[pat[i]] &= ~(1L << i);
    }
    return mask;
}
bool wu_manber(string txt, int patlen, vector<long> mask, int& result, string pat, int err_size) {
    vector<long> S(1, ~0);
    bool find = false;
    for (int i = 1; i < err_size + 1; i++) {
        S.push_back(S[i - 1] << 1);
    }
    for (int i = 0; i < txt.length(); i++) {
        vector<long>aux;
        aux.push_back(S[0] << 1 | mask[txt[i]]);
        for (int f = 1; f < err_size + 1; f++) {
            aux.push_back(((S[f] << 1) | mask[txt[i]]) & (S[f - 1] << 1) & (aux[f - 1] << 1) & (S[f - 1]));
        }
        S = aux;
        if ((S[err_size] & (1L << patlen - 1)) == 0) {
            result++;
            find=true;
        }
    }
    return find;
}
// void patternWM(string txt, string pat, vector<int>& result, int err_size) {
//     wu_manber(txt, pat.length(), pm(pat), result, pat, err_size);
// }

void run_wu_manber(vector<string> txt_set, vector<string> pat_set, bool c,int err_size){
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
                find =wu_manber(line,pat_set[j].length(),pm(pat_set[j]),count[j],pat_set[j],err_size);
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
