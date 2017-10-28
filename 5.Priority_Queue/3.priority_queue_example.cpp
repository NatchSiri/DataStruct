#include <iostream>
#include "priority_queue.h"
using namespace CP;
typedef bool(*CompFunc)(int, int);
bool myGreater(int a,int b) {
    return a > b;
}
typedef struct cmp {
    bool operator() (int a, int b) {
        return a < b;
    }
}cmp;
int main() {
    priority_queue<int> pq1;
    priority_queue< int, greater<int> > pq2;
    priority_queue<int, CompFunc> pq3(myGreater);
    priority_queue<int, CompFunc>
        pq4([](int x, int y){return x < y;}); // lambda
    priority_queue<int, cmp> pq5;
    int a[6] = {3, 4, 2, 5, 1, 6};
    priority_queue<int, CompFunc> pq6(a, 6, myGreater);
    for (int i = 0; i < 10; i++) {
        pq1.push(i);
        pq2.push(i);
        pq3.push(i);
        pq4.push(i);
        pq5.push(i);
    }
    std::cout << pq1.top() << std::endl;
    std::cout << pq2.top() << std::endl;
    std::cout << pq3.top() << std::endl;
    std::cout << pq4.top() << std::endl;
    std::cout << pq5.top() << std::endl;
    std::cout << pq6.size() << " " << pq6.top() << std::endl;
    return 0;
}
