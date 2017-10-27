#ifndef _CP_VECTOR_INCLUDED_
#define _CP_VECTOR_INCLUDED_
#include <iostream>
#include <stdexcept>
namespace CP {
    template <typename T>
    class vector {
        public :
            typedef T* iterator;
        private :
            T *mData;
            size_t mCap;
            size_t mSize;
            void rangeCheck(int n) {
                if (n < 0 || (size_t)n >= mSize) {
                    throw std::out_of_range("index of out range") ;
                }
            }
            void expand(size_t capacity) {
                T *arr = new T[capacity]();
                for (size_t i = 0; i < mSize; i++) {
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
            vector() {
                int cap = 1;
                mData = new T[cap]();
                mCap = cap;
                mSize = 0;
            }
            vector(size_t cap) {
                mData = new T[cap]();
                mCap = cap;
                mSize = cap;
            }
            vector(const vector<T>& a) {
                mData = new T[a.capacity()]();
                mCap = a.capacity();
                mSize = a.size();
                for (size_t i = 0; i < a.size(); i++) {
                    mData[i] = a[i];
                }
            }
            vector<T>& operator=(vector<T> other) {
                using std::swap;
                swap(this->mSize, other.mSize);
                swap(this->mCap, other.mCap);
                swap(this->mData, other.mData);
                return *this;
            }
            ~vector() {
                delete [] mData;
            }
            // Capacity Function
            bool empty() const {
                return mSize == 0;
            }
            size_t size() const {
                return mSize;
            }
            size_t capacity() const {
                return mCap;
            }
            void resize(size_t n) {
                if (n > mCap) {
                    expand(n);
                }
                if (n > mSize) {
                    T init = T();
                    for (size_t i = mSize;i < n; i++)
                    mData[i] = init;
                }
                mSize = n;
            }
            // Iterator
            iterator begin() {
                return mData;
            }
            iterator end() {
                return mData + mSize;
            }
            // Access
            T& at(int index) {
                rangeCheck(index);
                return mData[index];
            }
            T& at(int index) const {
                rangeCheck(index);
                return mData[index];
            }
            T& operator[](int index) {
                // not have rangeCheck because inheritance
                return mData[index];
            }
            T& operator[](int index) const {
                // not have rangeCheck because inheritance
                return mData[index];
            }
            // Modifier
            void push_back(const T& e) {
                insert(end(), e);
            }
            void pop_back() {
                mSize--;
            }
            void clear() {
                mSize = 0;
            }
            void erase(iterator it) {
                while (it + 1 != end()) {
                    *it = *(it + 1);
                    it++;
                }
                mSize--;
            }
            void insert(iterator it, const T& element) {
                size_t pos = it - begin();
                ensureCapacity(mSize + 1);
                for (size_t i = mSize; i > pos; i--) {
                    mData[i] = mData[i-1];
                }
                mData[pos] = element;
                mSize++;
            }
    };
}
#endif // _CP_VECTOR_INCLUDED_
