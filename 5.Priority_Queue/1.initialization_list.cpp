#include <iostream>
using namespace std;
class A {
    protected :
        int a0, a1;
    public :
        A() : a0(2), a1(3) {}
        A(int x0, int x1) : a0(x0), a1(x1) {}
};
class B : public A {
    public :
        const int b; // Can initialize constant variable
        B() : A(4, 5), b(a0 + a1) {}
};
class C : public A {
    public :
        int c;
        C() {
            A(4, 5); // Create Object
            c = a0 + a1;
        }
};
int main() {
    B b;
    cout << b.b << endl;
    C c;
    cout << c.c << endl;
    return 0;
}
