#include "global_include.hpp"
class Book {
public:

    Book(int id, int score) {
        this->id = id;
        this->score = score;
        done = false;
    }
    
    void findIt() {
        score -= score * 0.01;
    }

    int id;
    double score;
    bool done;
};

struct BookComparator
{
    // Compare 2 Player objects using name
    bool operator()(Book *Book1, Book *Book2)
    {
        return Book1->score > Book2->score;
    }
};
