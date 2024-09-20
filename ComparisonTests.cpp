#include <iostream>
#include <chrono>
#include <memory>
#include <limits>
#include "SmartPointer.h"
#include "UnqPtr_ShrdPtr.h"
#include "MemorySpan_MsPtr.h"

void runComparisonTests() {
    int N;
    while (true) {
        std::cout << "Enter the number of pointers to create and delete: ";
        std::cin >> N;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    
    // Тестирование времени создания и удаления "сырых" указателей
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        int* ptr = new int(i);
        delete ptr;
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;

    // Тестирование времени создания и удаления умных указателей STL
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        std::shared_ptr<int> ptr(new int(i));
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;

    // Тестирование времени создания и удаления ваших умных указателей
    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        SmartPointer<int> ptr(new int(i));
    }
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3 - start3;

    // Тестирование времени создания и удаления UnqPtr
    auto start4 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        UnqPtr<int> ptr(new int(i));
    }
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff4 = end4 - start4;

    // Тестирование времени создания и удаления ShrdPtr
    auto startShrd = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        ShrdPtr<int> ptrShrd(new UnqPtr<int>(new int(i)));
    }
    auto endShrd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff5 = endShrd - startShrd;

    // Тестирование времени создания и удаления MsPtr
    MemorySpan<int> span(N);
    auto start6 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        MsPtr<int> ptr = span.Locate(i);
    }
    auto end6 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff6 = end6 - start6;

    // Вывод результатов
    std::cout << "Time of creating and deleting " << N << " RawPtr: " << diff1.count() << " seconds.\n";
    std::cout << "Time of creating and deleting " << N << " Smart STL pointers: " << diff2.count() << " seconds.\n";
    std::cout << "Time of creating and deleting " << N << " SmrtPtr pointers: " << diff3.count() << " seconds.\n";
    std::cout << "Time of creating and deleting " << N << " UnqPtr pointers: " << diff4.count() << " seconds.\n";
    std::cout << "Time of creating and deleting " << N << " ShrdPtr pointers: " << diff5.count() << " seconds.\n";
    std::cout << "Time of creating and deleting " << N << " MsPtr pointers: " << diff6.count() << " seconds.\n";
}