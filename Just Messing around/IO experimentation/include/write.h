#ifndef WRITE_H
#define WRITE_H
#include <string>
#include <fstream>
using namespace std;

class write
{
    public:
        write();
        virtual ~write();
        void getfilename();
        string getinput();
        void establishpath();
        void getfileextension();
        string generatecode();
        void createfile();
        void writetofile(string);
        void writetofile(string input, int repetitions);
        void replaceword(string,string);
       // void modifyfile(string,char,char);
       void randomtest();
        void incrementiterations();

    protected:

    private:
    string filename, path , code , fileextension, input;
    int place,ext,codechoice;
    ofstream n;
    ifstream m;

};

#endif // WRITE_H
