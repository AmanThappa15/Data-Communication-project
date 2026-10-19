
#ifndef LINE_CODING_H
#define LINE_CODING_H

#include <string>
#include <vector>

// NRZ-L encoding: 0 = -1, 1 = +1
std::vector<int> encodeNRZL(const std::string& data);

// NRZ-I encoding: a 1 causes a transition
std::vector<int> encodeNRZI(const std::string& data);

#endif

