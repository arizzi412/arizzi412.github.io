//This program implements an application to find antonyms


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

const char * FILENAME = "antonyms.txt";
const int MAXWORD = 64;

class word_pair {
private:
    char * word1;
    char * word2;
    word_pair * next;
public:
    word_pair() { word1 = NULL; word2 = NULL; }
    ~word_pair();
    friend class antonyms;
};

class antonyms {
private:
    word_pair * head;
    word_pair * tail;
public:
    antonyms() { head = NULL; tail = NULL;}
    ~antonyms();
    void read_file();
    void append(char * w1, char * w2);
    word_pair * search(char * wordx);

};

word_pair::~word_pair() {
    delete [] word1;
    delete [] word2;
}

antonyms::~antonyms() {
    word_pair * p;

    while (head != NULL) {
        p = head;
        head = head->next;
        delete p;
    }
}

void antonyms::read_file() {
    char aword1[MAXWORD];
    char aword2[MAXWORD];

    ifstream ifs;

    ifs.open(FILENAME);
    if (ifs.fail()) {
        cerr << "The file is missing..." << endl;
        exit(0);
    }

    ifs >> aword1;
    while (!ifs.eof()) {
        ifs >> aword2;
        append(aword1, aword2);
        ifs >> aword1;
    }
}

void antonyms::append(char * w1, char * w2) {
    word_pair * p;

    p = new(nothrow) word_pair;
    if (p == NULL) {
        cerr << "memory allocation failed" << endl;
    }

    p->word1 = strdup(w1);
    p->word2 = strdup(w2);
    p->next = NULL;

    if (head == NULL) {
        head = p;
        tail = p;
    }
    else {
        tail->next = p;
        tail = p;
    }
}

word_pair * antonyms::search(char * c) {
    word_pair * p;
    int found;

    p = head;
    while (p != NULL) {
        found = strcmp(p->word1, c);
        if (found == 0) {
            cout << "word: '" << p->word1 << "' antonym: '"<< p->word2 << "'" << endl;
            return p;
            exit(4);
        }
        found = strcmp(p->word2, c);
        if (found == 0) {
            cout << "word: '" << p->word2 << "' antonym: '"<< p->word1 << "'" << endl;
            return p;
            exit(5);
        }
        p = p->next;
    }
    return p;
}

int main() {
    antonyms A;
    word_pair * w;

    A.read_file();

    char * c;
    c = new(nothrow) char[64];

    cout << "Begin entering words. Use period '.' to stop." << endl;
    cout << "--> ";

    cin >> c;
    while (!cin.fail() && (c[0] != '.')) {
        w = A.search(c);
        if (w == NULL) {
            cout << "word '" << c << "' not found." << endl;
        }
        cout << "--> ";
        cin >> c;
    }
}
