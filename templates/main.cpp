#include <bits/stdc++.h>
using namespace std;

string processing_file;


void init(ifstream*);
void readFiles(void);
void dumpResults(void);

void init(ifstream &in) {
    
}

void readFiles() {
    vector<string> files = {"first", "second"};
    for (string &file: files) {
        cout << "Processing file: " << file << endl;
        processing_file = file;
        ifstream in(file + ".txt");
        init(in);


        in.close();
        cout << "Done processing file: " << file << endl;
    }
}

void dumpResults() {
    ofstream out(processing_file + ".out");


    out.close();
}

int main()
{
    readFiles();
    dumpResults();
}
