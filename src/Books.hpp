#include "global_include.hpp"
class Book {
public:

    Book(int id, int score) {
        this->id = id;
        this->score = score;
    }

    int id, score;
    bool done;
};
