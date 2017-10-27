#ifndef _CP_PAIR_INCLUDED_
#define _CP_PAIR_INCLUDED_

namespace CP {

    template <typename T1, typename T2>
    class pair {
        public :
            T1 first;
            T2 second;

            // Constructor
            pair() {
                first = T1();
                second = T2();
            }
            pair(const T1& a, const T2& b)
                : first(a), second(b) {
            }
            pair(const pair<T1, T2>& a) {
                first = a.first;
                second = a.second;
            }
            // Operator
            pair<T1, T2>& operator= (const pair<T1, T2>& other) {
                first = other.first;
                second = other.second;
                return *this;
            }
            bool operator==(const pair<T1, T2> &other) {
                return (first == other.first && second == other.second);
            }
            bool operator<(const pair<T1, T2> &other) const {
                if (first == other.first) {
                    return second < other.second;
                }
                return first < other.first;
            }
            bool operator>(const pair<T1, T2> &other) const {
                /*if (*this == other) {
                    return false;
                }*/
                return !(*this < other);
            }

    };
}
#endif // _CP_PAIR_INCLUDED_
