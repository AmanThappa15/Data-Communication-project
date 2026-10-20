
#ifndef LINE_CODING_H
#define LINE_CODING_H

#include <string>
#include <vector>
std::vector<int> encodeNRZL(const std::string& data);
std::vector<int> encodeNRZI(const std::string& data);
std::vector<int> encodeManchester(const std::string& data);
std::vector<int> encodeDifferentialManchester(const std::string& data);
std::vector<int> encodeAMI(const std::string& data);
std::vector<int> encodeB8ZS(const std::string& data);
std::vector<int> encodeHDB3(const std::string& data);

#endif

