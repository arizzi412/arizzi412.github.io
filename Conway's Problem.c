#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "./ezipc.h"

int main( )
{
SETUP();
FILE * ptr_file;
int producer, squasher, printer, prevast;
char buffer[24];
char prev, current;
char* SM;
char* SM2;
SM= SHARED_MEMORY(1);
SM2= SHARED_MEMORY(1);
int endprod = 0;
int endsqu = 0;
int endprint = 0;
int counter = 0;
int prod = SEMAPHORE(SEM_BIN, 1);
int squ = SEMAPHORE(SEM_BIN, 0);
int print = SEMAPHORE(SEM_BIN, 0);

ptr_file = fopen("lab4.txt", "r");

producer = fork();

if( producer == 0)
{
    squasher = fork();
    if (squasher == 0)   // is printer
      {
      while (endprint != 1)
       {
       if(counter = 25)
       {
           printf('\n');
           counter = 0;
       }

          P(print);

          printf("%s", *SM2, stdout);
          fflush(stdout);
          V(squ);
          counter++;
       }
      }
    else   // is squasher  (squasher goes here
    {
      while (endsqu != 1)
      {

            P(squ);
            current = *SM;

           if (current = '*')
             {
               if(prevast == 1)
               {
                 *SM2 = '#';
               }
               else
               {
               prevast = 1;
               }
             }

           if (current != '*')
             {
               if (prevast == 1)
                 {
                   *SM2 = '*';
                   V(print);
                 }
             *SM2 = current;
             V(print);
             }
         V(prod);
      }
    }
}
else // is producer
{
while(fgets(buffer,20,ptr_file)!= NULL)
  {
  strcat(buffer,"EOL");
  for (int i = 0; i <20; i++)
   {
     P(prod);
    *SM = buffer[i];
      V(squ);
   }
  }

   endprod = 1;
   endsqu = 1;
   endprint = 1;
   wait();
}

}  // main


