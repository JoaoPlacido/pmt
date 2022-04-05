#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

using std::string;
using std::vector;

void run_kmp(vector<string> txt_set, vector<string> pat_set, bool c);
void run_aho_corasik(vector<string> txt_set, vector<string> pat_set, bool c);
void run_shift_or(vector<string> txt_set, vector<string> pat_set, bool c);
void run_sellers(vector<string> txt_set, vector<string> pat_set, bool c,int err_size);
void run_wu_manber(vector<string> txt_set, vector<string> pat_set, bool c,int err_size);

#endif // ALGORITHMS_HPP