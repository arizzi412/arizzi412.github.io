#include <iostream>
#include <fstream>
#include "write.h"


using namespace std;

int main()
{

 string z,y,w,f;
 //char Replace,Replacement;
int r;
int userinput, writecode;
write x;

Label1:
  cout << "Options: " << endl <<endl;

  cout << "1. Create a File:  " << endl <<"2. Write to a file: " << endl << "3. Exit" << endl << "4. Operational Experiments" << endl;

  cin >> userinput;

  switch (userinput)
  {
      case 1:

    x.establishpath();
    x.getfileextension();
    x.getfilename();
     cout << "Do you want to write to this file?" << endl << "1. Yes" << endl << "2. = No" << endl;
     cin >>userinput;
    switch (userinput)
    {
    case 1:
        w=z;
        goto Label2;
        break;
    case 2:

    x.createfile();

  }
     goto Label1;
        break;
      case 2:
        x.establishpath();
        x.getfileextension();
        x.getfilename();
     Label2:
         cout << "Do you want to use generated code?" << endl << "1. Yes" << endl << "2. No"<< endl;
         cin >> writecode;
         switch (writecode)
         {
             case 1:
           x.writetofile(x.generatecode());

            break;

            case 2:
            x.writetofile(x.getinput());
    break;
         }
    break;
        case 3:
            return 0;

        case 4:
            cout << "choose test:" << endl << "1. Random mean test" << endl << "2. Increment Iterations " << endl << "3. Word Replacement" <<endl;
            cin >> r;
            switch (r)
            {
            case 1:
                x.randomtest();
                break;

            case 2:
                x.incrementiterations();
                break;


            case 3:
            cout << "Input information on file to read from: "<< endl;
            x.getfilename();
            x.establishpath();
            x.getfileextension();
            string word;
            string replacement;
            cout << "Enter Word: "<< endl;
            cin >> word;
            cout << "Enter Replacement: "<< endl;
            cin >> replacement;
            x.replaceword(word,replacement);
            break;
            }
  }

    goto Label1;

 return 0;
}




