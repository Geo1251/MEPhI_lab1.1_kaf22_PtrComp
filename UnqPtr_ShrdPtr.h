#ifndef UNQPTR_SHRDPTR_H
#define UNQPTR_SHRDPTR_H

template <typename T>
class UnqPtr {
private:
    T* ptr;
public:
    UnqPtr(T* p = nullptr) : ptr(p) {}
    ~UnqPtr() { delete ptr; }
    UnqPtr(const UnqPtr&) = delete;
    UnqPtr& operator=(const UnqPtr&) = delete;
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete ptr;
            ptr = p;
        }
    }
};

template <typename T>
class ShrdPtr {
private:
    UnqPtr<T>* ptr;
    size_t* referenceCount;
public:
    ShrdPtr(UnqPtr<T>* p = nullptr) : ptr(p), referenceCount(new size_t(1)) {}
    ~ShrdPtr() { if (--(*referenceCount) == 0) { delete ptr; delete referenceCount; } }
    ShrdPtr(const ShrdPtr& sp) : ptr(sp.ptr), referenceCount(sp.referenceCount) { ++(*referenceCount); }
    ShrdPtr& operator=(const ShrdPtr& sp) {
        if (this != &sp) {
            if (--(*referenceCount) == 0) { delete ptr; delete referenceCount; }
            ptr = sp.ptr;
            referenceCount = sp.referenceCount;
            ++(*referenceCount);
        }
        return *this;
    }
    void reset(UnqPtr<T>* p = nullptr) {
        if (--(*referenceCount) == 0) {
            delete ptr;
            delete referenceCount;
        }
        ptr = p;
        referenceCount = new size_t(1);
    }
    T& operator*() { return **ptr; }
    T* operator->() { return &**ptr; }
};

#endif // UNQPTR_SHRDPTR_H