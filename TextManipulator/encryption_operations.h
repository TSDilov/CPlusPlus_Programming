#ifndef ENCRYPTION_OPERATIONS_H
#define ENCRYPTION_OPERATIONS_H

#include <string>

std::string encrypt(const std::string& input, int shift);

std::string decrypt(const std::string& input, int shift);

#endif