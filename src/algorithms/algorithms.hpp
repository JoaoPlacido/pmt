#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

void lpscompute(std::string pat, int patlen, std::vector<int>& lps);
int kmp(std::string txt,std::string pat,std::vector<int>& lps);
long* pm(std::string pat);
void shift_or(std::string txt, int patlen, long* mask, std::vector<int>& result, std::string pat);
void patternSO(std::string txt, std::string pat);

#endif // ALGORITHMS_HPP