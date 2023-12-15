#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include <string>

// Function to reverse a sentence while preserving word order
std::string reverseSentence(const std::string& input);

// Function to reverse a single word
std::string reverseSingleWord(const std::string& word);

// Function to count the number of vowels in a sentence
int countVowels(const std::string& input);

// Function to count the number of words in a sentence
int countWords(const std::string& input);

#endif