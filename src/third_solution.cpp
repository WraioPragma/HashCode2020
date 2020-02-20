// #include "Books.hpp"
#include "Input.hpp"
#include "Output.hpp"
using namespace std;

Input read;
Output out;
vector<pair<int, vector<int>>> signedUp;
int step = 1;

void greedy() {
    int sumDays = 0;
    while (sumDays <= read.days) {
        if (step == 0) {
            sort(read.libraries.begin(), read.libraries.end(), LibraryComparator());
            step = 1;
        }
        Library* lib = read.libraries[read.libraries.size() - 1];
        sumDays += lib->signUp - 1;
        if (sumDays > read.days) {
            break;
        }
        sort(lib->books.begin(), lib->books.end(), BookComparator());
        vector<int> new_books;
        // cerr << (read.days - sumDays)*(lib->ship) << endl;
        // cerr << lib->id << endl;
        for (long long i = 0; i < ((long long)(read.days - sumDays))*(lib->ship) && i < lib->books.size(); i++) {
            // cerr << lib->books[i]->done << endl;
            if (lib->books[i]->done) {
                break;
            }
            // cerr << i << endl;
            lib->books[i]->done = true;
            lib->books[i]->score = 0;
            new_books.push_back(lib->books[i]->id);
        }
        if (new_books.size() == 0) {
            read.libraries.pop_back();
            step--;
            if (read.libraries.size() == 0) {
                break;
            }
            continue;
        }
        signedUp.push_back({lib->id, new_books});
        read.libraries.pop_back();

        if (read.libraries.size() == 0) {
            break;
        }
        step--;
        if (step == 0) {
            for (int i = 0; i < read.libraries.size() - 1; i++) {
                read.libraries[i]->calculateValue();
            }
        }
    }
}

int main() {
    read.read_from_file();
    greedy();
    out.write_to_file(signedUp);
}
