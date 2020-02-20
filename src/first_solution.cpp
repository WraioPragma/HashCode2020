#include "Input.hpp"
#include "Output.hpp"

Input read;
Output out;
vector<pair<int,vector<Book*>>> signedUp;

void greedy() {
    int currentDay = 0, currentLib = 0;
    int holdTill = 0;
    bool signLock = false;
    for (int i = 0; i < read.days; i++) {
        bool new_book = false;
        // SignUp a new library
        if (!signLock && currentLib < read.libraries.size()) {
            signLock = true;
            holdTill = (read.libraries[currentLib]->signUp - 1);
        }

        for (int j = 0; j < currentLib; j++) {
            int num = read.libraries[signedUp[j].first]->ship;
            for (int k = 0; k < num; k++) {
                bool skip = false;
                if (read.libraries[signedUp[j].first]->books.size() == 0) {
                    break;
                }
                Book* book = read.libraries[signedUp[j].first]->books[read.libraries[signedUp[j].first]->books.size() - 1];
                while (book->done) {
                    read.libraries[signedUp[j].first]->books.pop_back();
                    if (read.libraries[signedUp[j].first]->books.size() == 0) {
                        skip = true;
                        break;
                    }
                    book = read.libraries[signedUp[j].first]->books[read.libraries[signedUp[j].first]->books.size() - 1];
                }
                if (skip) {
                    break;
                }

                book->done = true;
                signedUp[j].second.push_back(book);
                new_book = true;
                read.libraries[signedUp[j].first]->books.pop_back();
            }
        }



        // if (!new_book && !signLock) {
        //     break;
        // }

        if (holdTill > i) {
            signedUp.push_back({currentLib, {}});
            currentLib++;
            signLock = false;
        }

    }
}

int main() {
    read.read_from_file();
    greedy();
    out.write_to_file(signedUp);
}
