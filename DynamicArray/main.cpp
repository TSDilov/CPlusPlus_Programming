#include <iostream>
#include <algorithm>
#include <iterator>

int main(){
    std::cout << "Enter the size of the array: ";
    int size;
    std::cin >> size;

    int* dynamicArray = new int[size];

    std::cout << "Enter " << size << " integers:" << std::endl;

    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "Element" << i + 1 << ": ";
        std::cin >> dynamicArray[i];
    }

    std::cout << "You entered the following elements:" << std::endl;
    std::copy(dynamicArray, dynamicArray + size, std::ostream_iterator<int>(std::cout, " "));
    
    delete[] dynamicArray;
    dynamicArray = nullptr;
    
    return 0;
}
