#include "string_operations.h"
#include <algorithm>
#include <sstream>
#include <unordered_set>

std::string reverseSentence(const std::string& input) {
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

bool areAnagrams(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    std::string sortedStr1 = str1;
    std::string sortedStr2 = str2;

    std::sort(sortedStr1.begin(), sortedStr1.end());
    std::sort(sortedStr2.begin(), sortedStr2.end());

    return sortedStr1 == sortedStr2;
}

std::string removeDuplicates(const std::string& input) {
    std::string result;
    std::unordered_set<char> seenChars;

    for (char ch : input) {
        if (seenChars.find(ch) == seenChars.end())
        {
            result += ch;
            seenChars.insert(ch);
        }      
    }

    return result;
}

bool isPalindrome(const std::string& input){
    std::string cleandStr;
    for (auto ch : input) {
        if (std::isalnum(ch))
        {
            cleandStr += std::tolower(ch);
        }      
    }

    size_t length = cleandStr.length();
    for (size_t i = 0; i < length / 2; ++i) {
        if (cleandStr[i] != cleandStr[length - 1 - i]) {
            return false;
        }     
    }

    return true;
}

size_t findSubstring(const std::string& str, const std::string& substr) {
    size_t startingIndex = str.find(substr);
    if (startingIndex != std::string::npos) {
        return startingIndex;
    }

    return std::string::npos;  
}