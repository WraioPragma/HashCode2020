// #include "Books.hpp"
#include "Input.hpp"
#include "Output.hpp"
using namespace std;

Input read;
Output out;
vector<pair<int, vector<Book*>>> signedUp;

void greedy() {
    sort(read.libraries.begin(), read.libraries.end(), LibraryComparator());
    for (int i = 0; i < read.num_lib; i++) {
        cerr << read.libraries[i]->id << endl;
        sort(read.libraries[i]->books.begin(), read.libraries[i]->books.end(), BookComparator());
        signedUp.push_back({read.libraries[i]->id, read.libraries[i]->books});
    }
}

int main() {
    read.read_from_file();
    greedy();
    out.write_to_file(signedUp);
}
