#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

//shift or
long* pm(string pat) {
    long mask[256];
    int n = sizeof(mask) / sizeof(mask[0]);
    memset(mask, ~1, n * sizeof(mask[0]));
    for (int i = 0; i < (int)pat.length(); i++) {
        mask[pat[i]] &= ~(1L << i);
    }
    return mask;
}
void shift_or(string txt, int patlen, long* mask, vector<int>& result, string pat) {
    cout << " ";
    long S = ~1;
    for (int i = 0; i < (int)txt.length(); i++) {
        S |= mask[txt[i]];
        S <<= 1;
        if ((S & (1L << patlen)) == 0) {
            result.push_back(i - patlen + 1);
        }
    }
}

void patternSO(string txt, string pat) {
    vector<int> result;
    shift_or(txt, pat.length(), pm(pat), result, pat);
    if (result.size() > 0 || !result.empty()) {
        cout << "total ocurrances: " << result.size();
        cout << "\nthey occured at the folowing places: ";
        for (int i = 0; i < (int)result.size(); i++) {
            cout << result[i] << ";";
        }
    }
    else {
        cout << "no ocurrances";
    }
}