#include "encryption_operations.h"

std::string encrypt(const std::string& input, int shift) {
    std::string result = input;

    for (char& ch : result) {
        if (std::isalpha(ch)) {
            char base = std::isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
    }

    return result;
}

std::string decrypt(const std::string& input, int shift) {
    return encrypt(input, 26 - shift);
}