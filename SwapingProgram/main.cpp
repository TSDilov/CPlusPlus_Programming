#include <iostream>

void swapUsingPointers(int* a, int* b);
void swapUsingReferences(int& a, int& b);

int main(){
    int num1, num2;
    std::cout << "Enter the first integer: ";
    std::cin >> num1;

    std::cout << "Enter the second integer: ";
    std::cin >> num2;

    std::cout << "Initial values: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    swapUsingPointers(&num1, &num2);

    std::cout << "After swapping using pointers: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    swapUsingReferences(num1, num2);

    std::cout << "After swapping using references: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0;
}

void swapUsingPointers(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapUsingReferences(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
