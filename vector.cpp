#include "vector.h"
#include "filesystem_element.h"

template class Vector<FileSystemElement*>;
template class Vector<int>; //test

template <typename T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {}

template <typename T>
Vector<T>::Vector(int n) : size(n), capacity(n) {
    data = new T[capacity];
}
template <typename T>
Vector<T>::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        size--;
    }
}

template <typename T>
int Vector<T>::getSize() const {
    return size;
}

template <typename T>
int Vector<T>::getCapacity() const {
    return capacity;
}

template <typename T>
T& Vector<T>::operator[](int idx) {
    return data[idx];
}

template <typename T>
const T& Vector<T>::operator[](int idx) const {
    return data[idx];
}