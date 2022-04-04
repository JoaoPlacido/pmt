#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

using std::string;
using std::vector;

void lpscompute(std::string pat, int patlen, std::vector<int>& lps);
int kmp(std::string txt,std::string pat,std::vector<int>& lps);
long* pm(std::string pat);
void shift_or(std::string txt, int patlen, long* mask, std::vector<int>& result, std::string pat);
void patternSO(std::string txt, std::string pat);
void build_fsm(vector<string> pat_set, vector<vector<int>>& go_to,vector<vector<int>>& occ,vector<int>& fails);
bool aho_corasick(string txt, vector<int>& count,vector<vector<int>>& go_to, vector<vector<int>>& occ,vector<int>& fails);
void run_kmp(vector<string> txt_set, vector<string> pat_set, bool c);
void run_aho_corasik(vector<string> txt_set, vector<string> pat_set, bool c);

#endif // ALGORITHMS_HPP