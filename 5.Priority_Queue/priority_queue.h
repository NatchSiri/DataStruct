#ifndef _CP_PRIORITY_QUEUE_INCLUDED_
#define _CP_PRIORITY_QUEUE_INCLUDED_
#include <stdexcept>
#include <iostream>
namespace CP {
    template <class T>
    struct less : std::binary_function <T, T, bool> {
        bool operator() (const T& x, const T& y) const {
            return x < y;
        }
    };
    template <class T>
    struct greater : std::binary_function <T, T, bool> {
        bool operator() (const T& x, const T& y) const {
            return x > y;
        }
    };
}
namespace CP {
    template < typename T, typename Comp = CP::less<T> >
    class priority_queue {
        protected :
            T* mData;
            size_t mCap, mSize;
            Comp mLess;
            void expand(size_t capacity) {
                T *arr = new T[capacity]();
                for (size_t i = 0;i < mSize;i++) {
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
            void fixUp(size_t c) {
                T tmp = mData[c];
                while (c > 0) {
                    size_t p = c / 2;
                    if (mLess(tmp, mData[p])) {
                        break;
                    }
                    mData[c] = mData[p];
                    c = p;
                }
                mData[c] = tmp;
            }
            void fixDown(size_t p) {
                T tmp = mData[p];
                size_t c;
                while ((c = 2*p + 1) < mSize) {
                    if (c + 1 < mSize && mLess(mData[c], mData[c+1])) {
                        c++;
                    }
                    if (mLess(mData[c], tmp)) {
                        break;
                    }
                    mData[p] = mData[c];
                    p = c;
                }
                mData[p] = tmp;
            }
        public :
            // Constructor
            priority_queue(const Comp& c = Comp()) {
                mData = new T[1]();
                mCap = 1;
                mSize = 0;
                mLess = c;
            }
            priority_queue(const priority_queue<T, Comp>& pq) :
                    mData(new T[pq.mCap]()), mCap(pq.mCap),
                    mSize(pq.mSize), mLess(pq.mLess) {
                for (size_t i = 0; i < pq.mCap; i++) {
                    mData[i] = pq.mData[i];
                }
            }
            priority_queue(T a[], int n, const Comp& c = Comp()) :
                    mData(new T[n]()), mCap(n), mSize(n), mLess(c) {
                for (int i = 0; i < n; i++) {
                    mData[i] = a[i];
                }
                for (int i = (mSize - 1)/2; i >= 0; i--) {
                    fixDown(i);
                }
            }
            ~priority_queue() {
                delete [] mData;
            }
            // Copy Assignment Operator
            priority_queue<T, Comp>& operator=(priority_queue<T, Comp> other) {
                using std::swap;
                swap(mSize, other.mSize);
                swap(mCap, other.mCap);
                swap(mData, other.mData);
                swap(mLess, other.mLess);
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
            const T& top() const {
                if (size() == 0) {
                    throw std::out_of_range("index out of range");
                }
                return mData[0];
            }
            // Modifier
            void push(const T& e) {
                ensureCapacity(mSize + 1);
                mData[mSize++] = e;
                fixUp(mSize - 1);
            }
            void pop() {
                if (size() == 0) {
                    throw std::out_of_range("index out of range");
                }
                mData[0] = mData[mSize - 1];
                mSize--;
                fixDown(0);
            }
    };
}
#endif // _CP_PRIORITY_QUEUE_INCLUDED_
