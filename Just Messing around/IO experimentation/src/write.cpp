#include "write.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
write::write()
{

}

write::~write()
{
    //dtor
}


void write::getfilename()
{
    cout << "Input the name of your file:  " <<endl;
        cin.ignore(10000000, '\n');
        getline(cin,filename);
        return;
}

void write::establishpath()
{
    cout << "Location of File: " << endl<<"1. Desktop."  << endl << "2. Local"<< endl;
    cin >> place;
   switch (place)
   {
        case 1:
            path = "C:/Users/arizzi412/Desktop/";
        break;
        case 2:
            path = "";
        break;
   }
        return;
}

    void write::getfileextension()
    {
        cout << "What type of file is it?" << endl << "1) .txt" << endl <<"2) .docx" << endl << "3? .cpp" << endl << "4) .h" << endl;
        cin >> ext;

        switch (ext)
        {
        case 1:
            fileextension = ".txt";
            break;
        case 2:
            fileextension = ".docx";
            break;
        case 3:
            fileextension = ".cpp";
            break;
        case 4:
            fileextension = ".h";
            break;
        }
    }

    string write::getinput()
    {
        cout << "input what you want to write: " <<endl;
        cin.ignore(10000000, '\n');
        getline(cin,input);
        return input;
    }

    string write::generatecode()
    {
        string code;
            cout << "Choose code:" << endl << "1. Hello World" << endl << "2. Calculator" << endl;
            cin >> codechoice;

        switch (codechoice)
        {
        case 1:
            code = ("#include <iostream> \n using namespace std; \n int main() \n {cout <<  \"Hello World \" << endl;} ");
            return code;
            break;

        case 2:
            code = " // Program which performs addition, subtraction, multiplication and subtraction. \n#include <iostream>\nusing namespace std;\n// input function\n"
"void Input (float &x, float &y);\n"
"float a=1.0, b=1.0, result;\nchar operation;\n"
"int main ()\n{\ncout << \"Program which performs addition, subtraction, multiplication and subtraction.\";\n\n"
"cout << \"Please input calculation operation (eg. 1 + 2):\";\ncin >> a >> operation >> b;\n\nInput (a,b);\ncout << \"The answer is: \" << result << endl;\n\nreturn 0;\n}\n\n"
"void Input (float &x, float &y)\n{\na = x;\nb = y;\n\nswitch (operation)\n\n{case '+':\n"
"result = x + y;\nbreak;\n\ncase '-':\nresult = x - y;\nbreak;\n\ncase '*':\nresult = x * y;\nbreak;\n\ncase '/':\nresult = x / y;\nbreak;\n\n"
"default:\ncout << \"Improper operation. Please input a correct calculation operation: \";\ncin >> a >> operation >> b;\nInput (a, b);\n}\n};\n";
            break;
return code;
        }
        return code;
    }

void write::createfile()
{

      n.open(((path) + (filename + fileextension)),ios_base::app);

    return;
}


void write::writetofile(string input)
{
    n.open(((path)+(filename + fileextension)),ios_base::app);


    n << input<< endl;


    n.close();
return;

}



void write::writetofile(string input, int repetitions)
{

    n.open(((path)+(filename + fileextension)),ios_base::app);

    for(int i=1;i<= repetitions ; i++)
    {

    n << i << " " + input << endl;

    }

    n.close();
return;

}

void write::randomtest()
{
    srand(time(NULL));
    long long iterations;
    long long additions =0;
    long long num;
    int k;
    cout << "Do you want to output the results to a file?" << endl << "1. Yes" << endl << "Else no" << endl;
    cin >> k;
    if (k == 1)
    {
    establishpath();
    getfileextension();
    getfilename();
    n.open((path)+(filename + fileextension));
    }

    cout << "how many iterations do you want to run?" << endl;
    cin >> iterations;

    if (k==1)
    {
          for(long long i = 1 ; i <= iterations ; i++)
        {
            num = rand() % 100 + 1;
            n << num << " ";
            additions += num;

        }

        n << endl << "The sum of all of them is " << additions << endl;
        n << endl << "The mean is: " << (additions/iterations) << endl;
        n.close();
        return;
    }

    else
    {
    for(long long i = 1 ; i <= iterations ; i++)
        {
            num = rand() % 100 + 1;
            cout << num << "  ";
            additions += num;

        }

        cout << endl << "The sum of all of them is " << additions << endl;
        cout << endl << "The mean is: " << (additions/iterations) << endl;

        n.close();
        return;
    }
}

    void write::incrementiterations()
    {
    long long iterations;
    int k;
    int num = 1;
    cout << "Do you want to output the results to a file?" << endl << "1. Yes" << endl << "Else no" << endl;
    cin >> k;
    if (k == 1)
    {
    establishpath();
    getfileextension();
    getfilename();
    n.open((path)+(filename + fileextension));
    }

    cout << "how many iterations do you want to run?" << endl;
    cin >> iterations;

    if (k==1)
    {
          for(long long i = 1 ; i <= iterations ; i++)
        {
        num *= 2;
         n << num << " " << endl;
        }

        n.close();
        return;
    }

    else
    {
    for(long long i = 1 ; i <= iterations ; i++)
        {
            num *= 2;
            cout << num << "  " << endl;
        }
        return;
    }

        n.close();
    }


   void write:: replaceword(string word,string replacement)
   {
       string line;
       m.open((path)+(filename + fileextension));
       while (!m.eof())
       {

       getline(m,line);
       if (line.find(word) != string::npos)
        {
           word.replace(word.find(word), sizeof(replacement)-1, replacement);
        }
       }
       m.close();
       return;
   }

