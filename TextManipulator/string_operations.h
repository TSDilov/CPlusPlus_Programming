#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include <string>

std::string reverseSentence(const std::string& input);

std::string reverseSingleWord(const std::string& word);

int countVowels(const std::string& input);

int countWords(const std::string& input);

bool areAnagrams(const std::string& str1, const std::string& str2);

std::string removeDuplicates(const std::string& input);

bool isPalindrome(const std::string& str);

size_t findSubstring(const std::string& str, const std::string& substr);

#endif