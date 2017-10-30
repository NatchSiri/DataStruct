#include <iostream>
#include <functional>
using namespace std;
int main() {
    hash<string> hStr;
    hash<float> hFloat;
    hash<int> hInt;

    cout << hStr("C++") << endl;
    cout << hFloat(1.2f) << endl;
    cout << hInt(123) << endl;
    cout << hash<double>()(1.2) << endl;
    return 0;
}
