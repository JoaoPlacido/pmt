#include <iostream>
#include <string>
#include <vector>
#include <numeric>
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
void wu_manber(string txt, int patlen, vector<long> mask, vector<int>& result, string pat, int err_size) {
    vector<long> S(1, ~0);
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
            result.push_back(i);
        }

    }
}
void patternWM(string txt, string pat, vector<int>& result, int err_size) {
    wu_manber(txt, pat.length(), pm(pat), result, pat, err_size);
}
