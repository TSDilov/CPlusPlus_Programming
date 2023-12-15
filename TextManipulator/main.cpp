#include <iostream>
#include "string_operations.h"

int main(){
    int choice;
    std::string userInput;

    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Reverse Sentence" << std::endl;
        std::cout << "2. Reverse Single Word" << std::endl;
        std::cout << "3. Count Vowels" << std::endl;
        std::cout << "4. Count Words" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cout << "Enter your choice (0-4): ";
        std::cin >> choice;

        std::cin.ignore(); // Clear the newline character from the input buffer

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
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}
