#include <iostream>
#include <string>
#include <vector>
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
void kmp(string txt, string pat)
{
    int patlen = pat.size();
    int txtlen = txt.size();
    int sum = 0;
    vector<int> lps(patlen, 0);
    lpscompute(pat, patlen, lps);
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
            cout << (i - j) << "\n";//printa aonde achou
            j = lps[j - 1];
        }
        //funciona como um coiso pra printar a linha, maybe fazer um segundo array que checa se ja foi printado, array de boolean
        //colocar um somador toda vez que aparece a coisa
    }
    cout << sum;
}