#ifndef _CP_STACK_INCLUDED_
#define _CP_STACK_INCLUDED_
#include <stdexcept>
#include <iostream>
namespace CP {
    template <typename T>
    class stack {
        protected :
            T *mData;
            size_t mCap;
            size_t mSize;
            void expand(size_t capacity) {
                T *arr = new T[capacity]();
                for (size_t  i = 0; i < mSize; i++) {
                    arr[i] = mData[i];
                }
                delete [] mData;
                mData = arr;
                mCap = capacity;
            }
            void ensureCapacity(size_t capacity) {
                if (capacity > mCap) {
                    size_t s = (capacity > 2*mCap) ? capacity : 2*mCap;
                    expand(s);
                }
            }
        public :
            // Constructor
            stack() {
                mData = new T[1]();
                mCap = 1;
                mSize = 0;
            }
            stack(const stack<T>& s) {
                mData = new T[s.mCap]();
                mCap = s.mCap;
                mSize = s.size();
                for (size_t i = 0; i < s.size(); i++) {
                    mData[i] = s.mData[i];
                }
            }
            ~stack() {
                delete [] mData;
            }
            // Copy Assignment Operator
            stack<T>& operator=(stack<T>& other) {
                using std::swap;
                swap(mSize, other.mSize);
                swap(mCap, other.mCap);
                swap(mData, other.mData);
                return *this;
            }
            // Capacity Function
            bool empty() const {
                return mSize == 0;
            }
            size_t size() const {
                return mSize;
            }
            // Access
            const T& top() {
                if (size() == 0) {
                    throw std::out_of_range("index out of range");
                }
                return mData[size() - 1];
            }
            // Modifier
            void push(const T& e) {
                ensureCapacity(mSize + 1);
                mData[mSize++] = e;
            }
            void pop() {
                if (size() == 0) {
                    throw std::out_of_range("index out of range");
                }
                mSize--;
            }
    };
}

#endif // _CP_STACK_INCLUDED_
