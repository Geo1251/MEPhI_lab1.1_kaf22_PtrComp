#include "SmartPointer.h"
#include "UnqPtr_ShrdPtr.h"
#include "MemorySpan_MsPtr.h"
#include <chrono>
#include <iostream>
#include <limits> 

int runManualPerformanceTests() {

    int N;
    std::cout << "Enter the number of smart pointers to create and delete: ";
    while (!(std::cin >> N)) { // Проверяем, что ввод корректный
        std::cout << "Invalid input. Please enter an integer value: ";
        std::cin.clear(); // Очищаем флаг ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем некорректный ввод
    }

    // Тестирование времени создания и удаления умных указателей
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        SmartPointer<int> ptr(new int(i));
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to create and delete " << N << " smart pointers: " << diff.count() << " seconds.\n";

    std::cout << "Enter the number of regular pointers to create and delete: ";
    while (!(std::cin >> N)) { // Проверяем, что ввод корректный
        std::cout << "Invalid input. Please enter an integer value: ";
        std::cin.clear(); // Очищаем флаг ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем некорректный ввод
    }

    // Тестирование времени создания и удаления обычных указателей
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        int* ptr = new int(i);
        delete ptr;
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to create and delete " << N << " regular pointers: " << diff.count() << " seconds.\n";

        // Тестирование времени создания и удаления UnqPtr
    std::cout << "Enter the number of UnqPtr to create and delete: ";
    while (!(std::cin >> N)) {
        std::cout << "Invalid input. Please enter an integer value: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        UnqPtr<int> ptr(new int(i));
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to create and delete " << N << " UnqPtr: " << diff.count() << " seconds.\n";

    // Тестирование времени создания и удаления ShrdPtr
    std::cout << "Enter the number of ShrdPtr to create and delete: ";
    while (!(std::cin >> N)) {
        std::cout << "Invalid input. Please enter an integer value: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        ShrdPtr<int> ptr(new UnqPtr<int>(new int (i)));
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to create and delete " << N << " ShrdPtr: " << diff.count() << " seconds.\n";

    // Тестирование времени создания и удаления MsPtr
    std::cout << "Enter the number of MsPtr to create and delete: ";
    while (!(std::cin >> N)) {
        std::cout << "Invalid input. Please enter an integer value: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    MemorySpan<int> span(N);
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        MsPtr<int> ptr = span.Locate(i);
        *ptr = i;
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time to create and delete " << N << " MsPtr: " << diff.count() << " seconds.\n";

    return 0;
}
