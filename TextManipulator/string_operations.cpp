#include "string_operations.h"
#include <algorithm>
#include <sstream>

std::string reverseSentence(const std::string& input){
    std::string reversedSentence = input;
    std::reverse(reversedSentence.begin(), reversedSentence.end());
    return reversedSentence;
}

std::string reverseSingleWord(const std::string& word) {
    std::string reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}

int countVowels(const std::string& input) {
    return std::count_if(input.begin(), input.end(), [](char c) {
        return std::string("aeiouAEIOU").find(c) != std::string::npos;
    });
}

int countWords(const std::string& input) {
    std::stringstream ss(input);
    int wordCount = 0;
    std::string word;

    while (ss >> word) {
        ++wordCount;
    }

    return wordCount;
}

bool areAnagrams(const std::string& str1, const std::string& str2){
    if (str1.length() != str2.length()) {
        return false;
    }

    std::string sortedStr1 = str1;
    std::string sortedStr2 = str2;

    std::sort(sortedStr1.begin(), sortedStr1.end());
    std::sort(sortedStr2.begin(), sortedStr2.end());

    return sortedStr1 == sortedStr2;
}