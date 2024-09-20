#ifndef MEMORYSPAN_MSPTR_H
#define MEMORYSPAN_MSPTR_H

#include "UnqPtr_ShrdPtr.h"

template <typename T>
class MemorySpan; 

template <typename T>
class MsPtr {
private:
    T* ptr;
    MemorySpan<T>* span; 
public:
    MsPtr(MemorySpan<T>* s, size_t index) : span(s), ptr(&(*s)[index]) {}
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
};

template <typename T>
class MemorySpan {
private:
    T* data;
    size_t size;
public:
    MemorySpan(size_t size) : size(size) {
        data = new T[size];
    }
    ~MemorySpan() {
        delete[] data;
    }
    T& operator[](size_t index) {
        return data[index];
    }
    MsPtr<T> Locate(size_t index) {
        return MsPtr<T>(this, index);
    }
};

#endif // MEMORYSPAN_MSPTR_H