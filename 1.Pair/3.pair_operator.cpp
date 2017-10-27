#include <iostream>
#include "pair.h"
using namespace std;
int main() {
    CP::pair<int, string> a(10, "vishuu");
    CP::pair<int, string> b(a);

    cout << (a == b ? "YES" : "NO") << endl;

    CP::pair<int, string> c(999, "asdf");
    c = a = b;
    cout << (a == c ? "YES" : "NO") << endl;

    c.second = "abc";
    cout << (a == c ? "YES" : "NO") << endl;
    return 0;
}
