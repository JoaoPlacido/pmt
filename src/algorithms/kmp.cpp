#include <iostream>
#include <string>
#include <vector>
#include "algorithms.hpp"
#include <fstream>

using namespace std;
//kpm
void lpscompute(string pat, int patlen, vector<int>& lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < patlen) {
        if (pat[i] == pat[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int kmp(string txt, string pat,vector<int>& lps)
{
    int patlen = pat.size();
    int txtlen = txt.size();
    int sum = 0;
    int i = 0;
    int j = 0;
    while (i < txtlen) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        else {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
        if (j == patlen) {
            sum++;
            //cout << (i - j) << "\n";//printa aonde achou
            j = lps[j - 1];
        }
        //funciona como um coiso pra printar a linha, maybe fazer um segundo array que checa se ja foi printado, array de boolean
        //colocar um somador toda vez que aparece a coisa
    }
    //cout << sum;
    return sum;
}
void run_kmp(vector<string> txt_set, vector<string> pat_set, bool c){
    vector<vector<int>> lps_set;
    int l_txt_set = (int)txt_set.size();
    int l_pat_set = (int)pat_set.size();
    vector<int> count (l_pat_set,0);
    for(int i =0; i<l_pat_set;i++){
        int pat_len=(int)pat_set[i].size();
        lps_set.push_back(vector<int> (pat_len,0));
        lpscompute(pat_set[i],pat_len,lps_set[i]);        
    }
    for(int i=0;i<l_txt_set;i++){  
        cout << "arquivo: " <<txt_set[i] << endl;
        ifstream txt (txt_set[i]);
        string line;
        int n_line = 1;
        bool find = false;
        while (!txt.eof())
        {
            getline(txt,line);
            for(int p = 0;p<l_pat_set;p++){
                int line_count = kmp(line,pat_set[p],lps_set[p]);
                count[p] += line_count;
                if(line_count >0) find=true;
            }
            if(find and !c){
                cout << "line "<<n_line<<": "<<line<<endl;
            }
            n_line++;
            find =false;
        }
        txt.close();
        cout << "Quantidade de ocorrencias:" <<endl;
        for(int i =0; i<l_pat_set;i++){
        cout << pat_set[i]<<": "<<count[i]<<endl;
    }
    } 
}