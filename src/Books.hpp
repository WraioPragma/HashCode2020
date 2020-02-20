#include "global_include.hpp"
class Book {
public:

    Book(int id, int score) {
        this->id = id;
        this->score = score;
        done = false;
    }

    int id, score;
    bool done;
};

struct BookComparator
{
    // Compare 2 Player objects using name
    bool operator()(Book *Book1, Book *Book2)
    {
        if (Book1->done) {
            return false;
        } else if (Book2->done) {
            return true;
        }
        return Book1->score < Book2->score;
    }
};
