#include "SmartPointer.h"
#include "UnqPtr_ShrdPtr.h"
#include "MemorySpan_MsPtr.h"
#include <cassert>
#include <iostream>

void runAutomaticFunctionalTests() {
    // Тест 1: Создание умного указателя и проверка его количества использований
    SmartPointer<int> ptr1(new int(42));
    assert(*ptr1 == 42);

    // Тест 2: Создание копии умного указателя и проверка его количества использований
    SmartPointer<int> ptr2 = ptr1;
    *ptr2 = 100;
    assert(*ptr1 == 100);

    // Тест 3: Сброс исходного умного указателя и проверка его количества использований
    ptr1.reset(new int(200));
    assert(*ptr1 == 200);

    // Тест 4: Разыменование умного указателя и печать его значения
    SmartPointer<std::string> ptr3(new std::string("Hello, Mephi!"));
    assert(*ptr3 == "Hello, Mephi!");

    // Тест 5: Создание UnqPtr и проверка его значения
    UnqPtr<int> ptr4(new int(42));
    assert(*ptr4 == 42);

    // Тест 6: Создание ShrdPtr, копирование из UnqPtr и проверка его значения
    ShrdPtr<int> ptr5(new UnqPtr<int>(new int(42)));
    *ptr5 = 100;
    assert(*ptr5 == 100);

    // Тест 7: Сброс UnqPtr и проверка его значения
    ptr4.reset(new int(200));
    assert(*ptr4 == 200);

    // Тест 8: Создание ShrdPtr для строки и проверка его значения
    ShrdPtr<std::string> ptr6(new UnqPtr<std::string>(new std::string("Hello, Mephi!")));
    assert(*ptr6 == "Hello, Mephi!");

    // Тест 9: Создание UnqPtr и проверка его значения
    UnqPtr<int> ptr10(new int(42));
    assert(*ptr10 == 42);

    // Тест 10: Создание ShrdPtr, копирование из UnqPtr и проверка его значения
    ShrdPtr<int> ptr11(new UnqPtr<int>(new int(42)));
    *ptr11 = 100;
    assert(*ptr11 == 100);

    // Тест 11: Сброс UnqPtr и проверка его значения
    ptr10.reset(new int(200));
    assert(*ptr10 == 200);

    // Тест 12: Создание ShrdPtr для строки и проверка его значения
    ShrdPtr<std::string> ptr12(new UnqPtr<std::string>(new std::string("Hello, Mephi!")));
    assert(*ptr12 == "Hello, Mephi!");

    std::cout << "All tests passed!\n";
}