#include <iostream>
#include <algorithm>
#include "vector.h"
using namespace CP;
class Book {
    private :
        std::string name;
        double price;
    public :
        Book() : name(), price() {}
        Book(std::string n, double p) {
            name = n;
            price = p;
        }
        double getPrice() const {
            return price;
        }
        bool operator<(const Book& other) const { // sort, set, map
            return this->name < other.name;
        }
        bool operator==(const Book& other) const { // std::find
            return this->name == other.name;
        }
        friend std::ostream& operator<<(std::ostream& os, const Book& b) {
            os << '[' << b.name << ',' << b.price << ']';
            return os;
        }

};
struct BookPriceComp {
    bool operator() (const Book& a, const Book& b) {
        return a.getPrice() < b.getPrice();
    }
};
bool BookHighPriceComp(const Book& a, const Book& b) {
    return a.getPrice() > b.getPrice();
}
int main() {
    vector<Book> books;
    books.push_back(Book("Data", 203948));
    books.push_back(Book("Algorithm", 134559));
    books.push_back(Book("System", 523487));
    books.push_back(Book("Hardware", 351892));
    books.push_back(Book("Analysis", 723476));

    std::cout << "Before sort\n";
    for (Book b : books) {
        std::cout << b << std::endl;
    }
    std::sort(books.begin(), books.end());
    std::cout << "\nAfter sort\n";
    for (Book b : books) {
        std::cout << b << std::endl;
    }

    std::cout << "\nPrice sort\n";
    std::sort(books.begin(), books.end(), BookPriceComp());
    for (Book b : books) {
        std::cout << b << std::endl;
    }

    std::cout << "\nHigh Price sort\n";
    std::sort(books.begin(), books.end(), BookHighPriceComp);
    for (Book b : books) {
        std::cout << b << std::endl;
    }
    return 0;
}
