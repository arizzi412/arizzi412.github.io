#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "./ezipc.h"

int number_of_chairs, maximum_number_customers, pid, pid2, barberawake, barberfree, chairsleft, donecutting,barber_seat_empty, status, barbergohome = 0;

void my_handler(int);



void customer()
    {
    printf("A new customer enters... checks if chair is available...%d chairs left \n", SHOW(chairsleft));

      fflush(stdout);
    if(SHOW(chairsleft) == 0)
        {
        printf("No chairs left... Customer leaves...\n");
        fflush(stdout);
        exit(&status);
        }
    else
        {
        P(chairsleft);
        printf("Customer sits down in empty seat... ");
          fflush(stdout);
        printf("%d chairs left \n", SHOW(chairsleft));
          fflush(stdout);
        }
    if(SHOW(barberawake) == 0 && SHOW(barber_seat_empty) == 1)  // if barber is asleep and barber chair is empty
                {
                    printf("customer leaves waiting seat... ");
                    fflush(stdout);
                    V(chairsleft);   // free up a chair
                    printf("%d chairs left\n",SHOW(chairsleft));
                    fflush(stdout);
                    printf("customer sits in barbers chair\n");
                    fflush(stdout);
                    P(barber_seat_empty); // climbs into barber seat
                    printf("customer wakes barber...\n");
                    fflush(stdout);
                    V(barberawake);  // wake barber
                    P(donecutting);   // wait until hair is done cutting
                    printf("customer gets out of barber's seat\n");
                    fflush(stdout);
                      while(SHOW(barber_seat_empty)< 1)
                        {
                        V(barber_seat_empty);
                        }
                    printf("customer goes to pay and leaves\n");
                    fflush(stdout);

                }
    else if(SHOW(barber_seat_empty) == 0) // if someone is getting their hair cut;
                {
                 P(barber_seat_empty);  //wait until barber seat is free
                                 // when barber seat is free
                 printf("customer leaves waiting seat... ");
                 fflush(stdout);
                 V(chairsleft);
                 printf("%d chairs left\n",SHOW(chairsleft));
                 fflush(stdout);
                 printf("customer sits in barbers chair\n");
                 fflush(stdout);

                 P(barber_seat_empty); // climbs into barber seat
                 P(donecutting);   // wait until hair is done cutting
                 printf("customer gets out of barber's seat\n");
                 fflush(stdout);
                 while(SHOW(barber_seat_empty)< 1)
                        {
                        V(barber_seat_empty);
                        }
                 printf("customer goes to pay and leaves.\n");
                   fflush(stdout);


                }
     exit(&status);
    }

void barber()
    {
    while(1)
      {
     //  printf(" barberseatempty = %d, chairsleft = %d \n", SHOW(barber_seat_empty), SHOW(chairsleft));
      if (SHOW(barber_seat_empty) == 1) // if barber seat is empty
          {
          printf("Barber is sleeping\n");
            fflush(stdout);
          P(barberawake); // goes to sleep.  initialized to 0
          }
      if(barbergohome == 1)
          {
          break;
          }

      if (SHOW(barber_seat_empty) == 0) // if barber is awake and someone in barber seat
          {
          printf("Barber starts cutting hair\n");
          fflush(stdout);
          sleep(4);
          printf("Done cutting hair...\n");
          fflush(stdout);
          V(donecutting);
          sleep(2);
          }
      }
    }

int main()
{

SETUP();
signal(SIGUSR1, my_handler);
printf("\nHow many chairs?: ");
  fflush(stdout);
scanf("%d", &number_of_chairs);

printf("\nWhat is the maximum number of customers?: ");
  fflush(stdout);
scanf("%d", &maximum_number_customers);

barberfree = SEMAPHORE(SEM_BIN,1);
chairsleft = SEMAPHORE(SEM_CNT, number_of_chairs);
barberawake= SEMAPHORE(SEM_BIN, 0);
donecutting = SEMAPHORE(SEM_BIN,0);
barber_seat_empty = SEMAPHORE(SEM_BIN,1);


    pid = fork();
    if(pid != 0)
        {
          barber();
        }

    if (pid == 0)
    {
        for(int i = 0; i < maximum_number_customers; i++)
      {
            sleep(2);
            pid2 = fork();
            if (pid2 == 0)
                {
                customer();
                exit(&status);
                }

          }
      wait();
      exit(&status);
    }
    printf("Barber closes up shop and goes home");
    return 0;
}


void my_handler(int signum)
{

        printf("Received SIGUSR1!\n");

         while(SHOW(barberawake)< 1)
           {
           V(barberawake);
           }
        barbergohome = 1;
}
