#include "Books.hpp"
using namespace std;

class Library {
public:
    Library (vector<Book*> books, int signUp, int ship) {
        this->signUp = signUp;
        this->ship = ship;
        this->books = books;
    }
    int signUp, ship;
    vector<Book*> books;
};