#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include "algorithms.hpp"
using namespace std;

//shift or
vector<long> pm(string pat) {
    vector<long> mask(256);
    for (int i = 0; i < 256; i++) {
        mask[i] = ~0;
    }
    for (int i = 0; i < (int)pat.length(); i++) {
        mask[pat[i]] &= ~(1L << i);
    }
    return mask;
}
bool shift_or(string txt, int patlen, vector<long> mask, int& result, string pat) {
    bool find = false;
    long S = ~1;
    for (int i = 0; i < (int)txt.length(); i++) {
        S |= mask[txt[i]];
        S <<= 1;
        if ((S & (1L << patlen)) == 0) {
            result++;
            find = true;
        }
    }
    return find;
}

void run_shift_or(vector<string> txt_set, vector<string> pat_set, bool c) {
    vector<vector<int>> lps_set;
    int l_txt_set = (int)txt_set.size();
    int l_pat_set = (int)pat_set.size();
    vector<int> count(l_pat_set, 0);
    for (int i = 0; i < l_txt_set; i++) {
        ifstream txt(txt_set[i]);
        string line;
        int n_line = 1;
        while (!txt.eof()) {
            getline(txt, line);
            bool find = false;
            for (int j = 0; j < l_pat_set; j++) {
                find = shift_or(line,pat_set[j].length(),pm(pat_set[j]),count[j],pat_set[j]);
            }
            if (find and !c) {
                cout << "line " << n_line << ": " << line << endl;
            }
            n_line++;
        }
        txt.close();
    }
    if (c) {
        for (int i = 0; i < l_pat_set; i++) {
            cout << pat_set[i] << ": " << count[i] << endl;
        }
    }
}