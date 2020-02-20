#include "Library.hpp"

using namespace std;

class Input{
public:
	/* all of our data attributes */
	Input() {

	}

	void read_from_file() {
		cin >> num_books >> num_lib >> days;
		for (int i = 0; i < num_books; i++) {
			int score;
			cin >> score;
			books.push_back(new Book(i, score));
		}
		for (int i = 0; i < num_lib; i++) {
			int num_lib_books, signUp, ship;
			cin >> num_lib_books >> signUp >> ship;
			vector<Book*> lib_books;
			for (int i = 0; i < num_lib_books; i++) {
				int bookId;
				cin >> bookId;
				lib_books.push_back(books[bookId]);
			}
			libraries.push_back(new Library(lib_books, signUp, ship));
		}
	}

	int num_books, num_lib, days;
	vector<Book*> books;
	vector<Library*> libraries;
};






