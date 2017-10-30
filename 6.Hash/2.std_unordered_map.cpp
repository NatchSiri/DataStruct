#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<string, int> facultyCode;
    facultyCode["engineering"] = 21;
    facultyCode["accounting"] = 26;
    facultyCode["science"] = 23;
    cout << facultyCode["engineering"] << endl;
    cout << facultyCode["accounting"] << endl;
    cout << facultyCode["science"] << endl;
    return 0;
}
