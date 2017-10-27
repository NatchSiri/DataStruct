#include <iostream>
using namespace std;
template <typename T>
class V {
    protected :
        T *mData;
    public :
        V(int c) {
            cout << "V()" << endl;
            mData = new T[c];
        }
        ~V() {
            cout << "~V()" << endl;
            delete [] mData;
        }
};
class Q {
    public :
    Q() {
        cout << "\tQ()" << endl;
    }
    ~Q() {
        cout << "\t~Q()" << endl;
    }
};
int main() {
    V<Q> v(3);
    Q q;
}
