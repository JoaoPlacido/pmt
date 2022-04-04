#include <iostream>
#include <string>
#include <vector>
using namespace std;

//shift or
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
void shift_or(string txt, int patlen, vector<long> mask, vector<int>& result, string pat) {
    long S = ~1;
    for (int i = 0; i < txt.length(); i++) {
        S |= mask[txt[i]];
        S <<= 1;
        if ((S & (1L << patlen)) == 0) {
            result.push_back(i - patlen + 1);
        }
    }
}

void patternSO(string txt, string pat, vector<int>& result) {
    shift_or(txt, pat.length(), pm(pat), result, pat);
}