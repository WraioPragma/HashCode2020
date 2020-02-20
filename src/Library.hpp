#include "Books.hpp"
using namespace std;

class Library
{
public:
    Library(vector<Book *> books, int signUp, int ship, int id)
    {
        this->id = id;
        this->signUp = signUp;
        this->ship = ship;
        this->books = books;
        calculateValue();
    }

    void calculateValue() {
        value = 0;
        for (Book* book: books) {
            value += book -> score;
        }
    }
    int value;
    int signUp, ship, id;
    vector<Book *> books;
};

struct LibraryComparator
{
    // Compare 2 Player objects using name
    bool operator()(Library *library1, Library *library2)
    {
        if (library1->value == library2->value) {
            library1->signUp > library2->signUp;
        }
        return library1->value > library2->value;
    }
};
