#include <iostream>
#include <functional>
#include <unordered_map>
using namespace std;
class Book {
    public :
        string title;
        int edition;
        double price;
        Book(string title = "Data", int ed = 1, double price = 199.0) :
                title(title), edition(ed), price(price) {
        }
        bool operator==(const Book &rhs) const {
            return title == rhs.title && edition == rhs.edition;
        }
};
class BookHasher {
    public :
        size_t operator() (const Book& b) const {
            return hash<string>() (b.title) ^ hash<int>() (b.edition);
        }
};
int main() {
    unordered_map<Book, string, BookHasher> umap = {
        { {"Data Structures", 1, 200}, "reserved" },
        { {"Algorithm", 5, 200}, "available"}
    };
    Book b1("Data Structures", 1);
    Book b2("Data Structures", 3);
    Book b3("algorithm", 5);
    cout << umap[b1] << endl;
    cout << umap[b2] << endl;
    cout << umap[b3] << endl;
    cout << (umap[b3] == "") << endl;
    return 0;
}
