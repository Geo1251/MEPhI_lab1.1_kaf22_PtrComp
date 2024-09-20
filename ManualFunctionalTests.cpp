#include <iostream>
#include "SmartPointer.h"
#include "UnqPtr_ShrdPtr.h"
#include "MemorySpan_MsPtr.h"
#include <limits>

int runManualFunctionalTests() {

    // Тест 1: Создание умного указателя и проверка его количества использований
    std::cout << "Enter a number for the first smart pointer: ";
    int num1;
    while (!(std::cin >> num1)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    SmartPointer<int> ptr1(new int(num1));
    std::cout << "You entered: " << *ptr1 << std::endl;

    // Тест 2: Создание копии умного указателя и проверка его количества использований
    std::cout << "Enter a new number for the first smart pointer: ";
    int num2;
    while (!(std::cin >> num2)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    SmartPointer<int> ptr2 = ptr1;
    *ptr2 = num2;
    std::cout << "After copying the first smart pointer contains: " << *ptr1 << std::endl;

    // Тест 3: Сброс исходного умного указателя и проверка его количества использований
    std::cout << "Enter a new number for the first smart pointer: ";
    int num3;
    while (!(std::cin >> num3)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    ptr1.reset(new int(num3));
    std::cout << "After resetting the first smart pointer contains: " << *ptr1 << std::endl;

    // Тест 4: Разыменование умного указателя и печать его значения
    std::cout << "Enter a string for the third smart pointer: ";
    std::string str;
    std::cin >> str;

    SmartPointer<std::string> ptr3(new std::string(str));
    std::cout << "The third smart pointer contains: " << *ptr3 << std::endl;

    // Тест 5: Использование оператора стрелки для вызова метода объекта, на который указывает умный указатель
    std::cout << "Enter a string for the fourth smart pointer: ";
    std::cin >> str;

    SmartPointer<std::string> ptr4(new std::string(str));
    std::cout << "The length of the string is: " << ptr4->size() << std::endl;

     // Тест 6: Создание и использование UnqPtr
    std::cout << "Enter a number for the UnqPtr: ";
    int num6;
    while (!(std::cin >> num6)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    UnqPtr<int> unqPtr6(new int(num6));
    std::cout << "You entered: " << *unqPtr6 << std::endl;

    // Тест 8: Создание и использование ShrdPtr
    std::cout << "Enter a number for the ShrdPtr: ";
    int num8;
    while (!(std::cin >> num8)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    ShrdPtr<int> shrdPtr8(new UnqPtr<int>(new int(num8)));
    std::cout << "You entered: " << *shrdPtr8 << std::endl;

    // Тест 9: Создание и использование MsPtr
    std::cout << "Enter a number for the MsPtr: ";
    int num9;
    while (!(std::cin >> num9)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    MemorySpan<int> span9(1);
    MsPtr<int> msPtr9 = span9.Locate(0);
    *msPtr9 = num9;
    std::cout << "You entered: " << *msPtr9 << std::endl;

    std::cout << "All manual tests passed!\n";

    return 0;
}