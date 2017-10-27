#include <iostream>
#include <vector>
#include <algorithm>
#include "pair.h"
using namespace std;
int main() {
    vector< CP::pair<int, string> > v;
    v.push_back( CP::pair<int, string> (10, "asdf") );
    v.push_back( CP::pair<int, string> (10, "zzz") );
    v.push_back( CP::pair<int, string> (10, "ddd") );
    v.push_back( CP::pair<int, string> (5, "asdf") );
    v.push_back( CP::pair<int, string> (3, "X") );
    v.push_back( CP::pair<int, string> (1, "asdf") );

    sort(v.begin(), v.end());

    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    cout << (v[0] > v[1] ? "YES" : "NO") << endl;
    return 0;
}
