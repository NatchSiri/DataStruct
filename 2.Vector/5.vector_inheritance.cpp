#include <iostream>
#include <stdexcept>
#include "vector.h"
using namespace CP;
template <typename T>
class neoVector : public vector<T> {
    public :
        //using vector<T>::vector; // use the constructors from vector
        friend std::ostream& operator<<(std::ostream& os, const neoVector& v) {
            os << "[";
            for (size_t i = 0; i < v.size() - 1; i++) {
                os << v[i] << ", ";
            }
            os << v[v.size() - 1] << "]";
            return os;
        }
};
int main() {
    neoVector<int> nv;
    nv.push_back(1);
    nv.push_back(2);
    nv.push_back(3);
    std::cout << nv << std::endl;
    return 0;
}
