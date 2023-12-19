#include <iostream>
#include <string>
#include "string_operations.h"
#include "encryption_operations.h"

void displayMenu() {
    int choice;
    std::string userInput;

    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Reverse Sentence" << std::endl;
        std::cout << "2. Reverse Single Word" << std::endl;
        std::cout << "3. Count Vowels" << std::endl;
        std::cout << "4. Count Words" << std::endl;
        std::cout << "5. Check Anagrams" << std::endl;
        std::cout << "6. Remove Duplicates" << std::endl;
        std::cout << "7. Encrypt/Decrypt" << std::endl;
        std::cout << "8. Check Polindrome" << std::endl;
        std::cout << "9. Find for substring" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cout << "Enter your choice (0-9): ";
        std::cin >> choice;

        std::cin.ignore();

        switch (choice) {
            case 0:
                std::cout << "Exiting program." << std::endl;
                break;
            case 1: {
                // Reverse the entire sentence
                std::cout << "Enter a sentence: ";
                std::getline(std::cin, userInput);
                std::cout << "Reversed Sentence: " << reverseSentence(userInput) << std::endl;
                break;
            }
            case 2: {
                // Reverse a single word
                std::cout << "Enter a word: ";
                std::cin >> userInput;
                std::cout << "Reversed Word: " << reverseSingleWord(userInput) << std::endl;
                break;
            }
            case 3: {
                // Count vowels
                std::cout << "Enter a sentence: ";
                std::getline(std::cin, userInput);
                std::cout << "Number of vowels: " << countVowels(userInput) << std::endl;
                break;
            }
            case 4: {
                // Count words
                std::cout << "Enter a sentence: ";
                std::getline(std::cin, userInput);
                std::cout << "Number of words: " << countWords(userInput) << std::endl;
                break;
            }
            case 5: {
                // Check if two strings are anagrams
                std::cout << "Enter the first string: ";
                std::getline(std::cin, userInput);
                std::string str1 = userInput;

                std::cout << "Enter the second string: ";
                std::getline(std::cin, userInput);
                std::string str2 = userInput;

                if (areAnagrams(str1, str2)) {
                    std::cout << "The strings are anagrams." << std::endl;
                } else {
                    std::cout << "The strings are not anagrams." << std::endl;
                }
                break;
            }
            case 6: {
                // Remove duplicates
                std::cout << "Enter a string: ";
                std::getline(std::cin, userInput);
                std::cout << "String after removing duplicates: " << removeDuplicates(userInput) << std::endl;
                break;
            }
            case 7: {
                // Encrypt/Decrypt
                std::cout << "Enter a string: ";
                std::getline(std::cin, userInput);

                int shift;
                std::cout << "Enter the shift value: ";
                std::cin >> shift;

                std::cin.ignore();

                std::string encrypted = encrypt(userInput, shift);
                std::string decrypted = decrypt(encrypted, shift);

                std::cout << "Encrypted: " << encrypted << std::endl;
                std::cout << "Decrypted: " << decrypted << std::endl;
                break;
            }
            case 8: {
                // Check if a string is polindrome
                std::cout << "Enter a string: ";
                std::getline(std::cin, userInput);
                std::string str = userInput;

                if (isPalindrome(str)) {
                    std::cout << "The string is polindrome." << std::endl;
                } else {
                    std::cout << "The string is not polindrome." << std::endl;
                }
                break;
            }
            case 9: {
                // Find substring into string
                std::cout << "Enter a string: ";
                std::getline(std::cin, userInput);
                std::string str = userInput;

                std::cout << "Enter a subString: ";
                std::getline(std::cin, userInput);
                std::string subStr = userInput;

                size_t index = findSubstring(str, subStr);
                if (index == std::string::npos) {
                    std::cout << "There isn't such substring into the string." << std::endl;
                } else {
                    std::cout << "The substring become at index: " << index << " of the string." << std::endl;
                }
                break;
            }
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 0);
}