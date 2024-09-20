#include "SmartPointer.h"
#include "UnqPtr_ShrdPtr.h"
#include "MemorySpan_MsPtr.h"
#include <chrono>
#include <iostream>

void runAutomaticPerformanceTests() {
    const int N = 1000000;

    // Тестирование времени создания и удаления умных указателей
    auto startSmart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        SmartPointer<int> ptrSmart(new int(i));
    }
    auto endSmart = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSmart = endSmart - startSmart;
    std::cout << "Time to create and delete " << N << " SmrtPtr: " << diffSmart.count() << " seconds.\n";

    // Тестирование времени создания и удаления UnqPtr
    auto startUnq = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        UnqPtr<int> ptrUnq(new int(i));
    }
    auto endUnq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffUnq = endUnq - startUnq;
    std::cout << "Time to create and delete " << N << " UnqPtr: " << diffUnq.count() << " seconds.\n";

    // Тестирование времени создания и удаления ShrdPtr
    auto startShrd = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        ShrdPtr<int> ptrShrd(new UnqPtr<int>(new int(i)));
    }
    auto endShrd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffShrd = endShrd - startShrd;
    std::cout << "Time to create and delete " << N << " ShrdPtr: " << diffShrd.count() << " seconds.\n";

    // Тестирование времени создания и удаления MsPtr
    MemorySpan<int> span(N);
    auto startMs = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        MsPtr<int> ptrMs = span.Locate(i);
    }
    auto endMs = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffMs = endMs - startMs;
    std::cout << "Time to create and delete " << N << " MsPtr: " << diffMs.count() << " seconds.\n";

    // Тестирование времени создания и удаления обычных указателей
    auto startReg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        int* ptrReg = new int(i);
        delete ptrReg;
    }
    auto endReg = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffReg = endReg - startReg;
    std::cout << "Time to create and delete " << N << " regular pointers: " << diffReg.count() << " seconds.\n";
}