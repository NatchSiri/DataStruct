#ifndef _CP_QUEUE_INCLUDED_
#define _CP_QUEUE_INCLUDED_
#include <stdexcept>
#include <iostream>
namespace CP {
    template <typename T>
    class queue {
        protected :
            T *mData;
            size_t mCap, mSize, mFront;
            void expand(size_t capacity) {
                T *arr = new T[capacity]();
                for (size_t i = 0; i < mSize; i++) {
                    arr[i] = mData[(mFront + i) % mCap];
                }
                delete [] mData;
                mData = arr;
                mCap = capacity;
                mFront = 0;
            }
            void ensureCapacity(size_t capacity) {
                if (capacity > mCap) {
                    size_t s = (capacity > 2*mCap) ? capacity : 2*mCap;
                    expand(s);
                }
            }
        public :
            // Constructor
            queue() {
                mData = new T[1];
                mCap = 1;
                mSize = mFront = 0;
            }
            queue(const queue<T>& q) {
                mData = new T[q.mCap];
                mCap = q.mCap;
                mSize = q.size();
                for (size_t i = 0; i < q.mCap; i++) {
                    mData[i] = q.mData[i];
                }
                mFront = q.mFront;
            }
            ~queue() {
                delete [] mData;
            }
            // Copy Assignment Operator
            queue<T>& operator=(queue<T> other) {
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
            const T& front() {
                if (size() == 0) {
                    throw std::out_of_range("index out of range");
                }
                return mData[mFront];
            }
            const T& back() {
                if (size() == 0) {
                    throw std::out_of_range("index out of range");
                }
                return mData[(mFront + mSize - 1) % mCap];
            }
            // Modifier
            void push(const T& e) {
                ensureCapacity(mSize + 1);
                mData[(mFront + mSize) % mCap] = e;
                mSize++;
            }
            void pop() {
                if (size() == 0) {
                    throw std::out_of_range("index out of range");
                }
                mFront = (mFront + 1) % mCap;
                mSize--;
            }

    };
}
#endif // _CP_QUEUE_INCLUDED_
