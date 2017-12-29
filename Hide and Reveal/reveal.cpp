
// brief This program implements a program that reads a file and output the hidden message if there is one

#include <cstring>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <iostream>
using namespace std;

const int MAXM = 141;

class image {
private:
    int rows;
    int cols;
    int ** img;

public:
    image();
    void read_image(char * filename) ;
    void hide_message(char * msg);
    void write_image(char * outname);
    void reveal_message(char * msg);

};

image::image(){

}

void image::read_image(char * filename) {

    ifstream ifs;
    ifs.open(filename);

    if (ifs.fail()) {
        cerr << "The file is missing..." << endl;
        exit(5);
    }

    ifs >> rows;
    ifs >> cols;

    img = new (nothrow) int * [rows];

    for (int i = 0; i < rows; i++) {
        img[i] = new (nothrow) int [cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ifs >> img[i][j];
        }
    }

}

void image::hide_message(char * msg) {

    if (((strlen(msg) + 1) * 8) > (rows * cols)) {
        cerr << "The image isn't large enough to hide the message..." << endl;
        exit(0);
    }

    char c;
    int b;
    int bitcount = 0;
    int i, j;

    for (int a = 0; a <= strlen(msg); a++) {
        c = msg[a];
        for (int n = 0; n < 8; n++) {
            b = (c >> n) & 1;
            i = bitcount % rows;
            j = bitcount / rows;
            img[i][j] = img[i][j] & (~1); // force last bit to 0
            img[i][j] = img[i][j] | b;
            bitcount++;
        }
    }

}

void image::write_image(char * filename) {

    ofstream fout;
    fout.open(filename);

    fout << rows << " " << cols << " " << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fout << img[i][j] << " ";
        }
        fout << endl;
    }

    fout.close();

}

void image::reveal_message(char * msg) {

    char c;
    int b;
    int bitcount = 0;
    int i, j;
    int a = 0;

    do {
        c = '\0';
        for (int n = 0; n < 8; n++) {
            i = bitcount % rows;
            j = bitcount / rows;
            b = img[i][j] & 1;
            c = c | (b << n);
            bitcount++;
        }
        msg[a] = c;
        a++;
    } while (bitcount < (140 * 8) && (c != '\0'));

}

int main(int argc, char * argv[] ) {
    image img;
    char message[MAXM];
    bool ismessage = true;

    img.read_image(argv[1]);
    img.reveal_message(message);

    for (int i = 0; i < strlen(message); i++){
        if (!isprint(message[i])) {
            ismessage = false;
            cout << "No message..." << endl;
            exit(6);
        }
    }

    if (ismessage) {
        cout << message << endl;
    }

}
