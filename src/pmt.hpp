#ifndef PMT_HPP
#define PMT_HPP
#include <vector>
#include <string>
std::vector<std::string> get_pattern_list(std::string pattern);
void pmt(int emax, bool p, bool a,bool c, std::string pattern, std::string algorithm,std::vector<std::string> textfiles);

#endif // PMT_HPP