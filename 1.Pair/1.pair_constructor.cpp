#include <iostream>
#include "pair.h"
using namespace std;
int main() {
    CP::pair<int, double> a;
    cout << a.first << " " << a.second << endl;
    a.first = 1;
    a.second = 2.0;
    cout << a.first << " " << a.second << endl;

    CP::pair<int, double> b(a);
    cout << b.first << " " << b.second << endl;

    CP::pair<int, double> c(10, 3.14);
    cout << c.first << " " << c.second << endl;
    return 0;
}
