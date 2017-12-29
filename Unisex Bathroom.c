#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "./ezipc.h"

void quitHandler(int);
int numM = 0;
int numF = 0;
int customerNum = 1;

int main()
{
SETUP();
signal(SIGINT, quitHandler);
int r;
int time;
int x;
int pid;
char sex;
FILE * ptr_file;

int Stall = SEMAPHORE(SEM_BIN, 1);
int semM = SEMAPHORE(SEM_CNT, 0);
int semF = SEMAPHORE(SEM_CNT,0);

int * malesWaiting = SHARED_MEMORY(8);
int * MCurrentUsing = SHARED_MEMORY(8);
int * FCurrentUsing = SHARED_MEMORY(8);
int * femalesWaiting = SHARED_MEMORY(8);
int *numStall = SHARED_MEMORY(8);
*malesWaiting = 0;
*MCurrentUsing = 0;
*femalesWaiting = 0;
*FCurrentUsing = 0;

ptr_file = fopen("unisex.txt", "r");

	printf("Input number of stalls: \n");
	scanf("%d", &x);
 int semStall = SEMAPHORE(SEM_CNT, x);
 *numStall = x;

label:
r = fscanf(ptr_file, "%d %c", &time, &sex);
if (r != EOF)
{
	if(sex == 'M')
		{
			numM++;
		}
	else
		{
			numF++;
		}

	pid = fork();
	if (pid == 0)
		{
			sleep(time);

			if (sex == 'M')
				{
         printf("\nCHECK 1!\n");
					P(Stall);
     printf("\nCHECK 2!\n");
					if (*FCurrentUsing + *femalesWaiting == 0)
						{
							*MCurrentUsing += 1;
							V(semM);
						}
					else
						{
							*malesWaiting += 1;
						}
			V(Stall);
      printf("\nCHECK 3!\n");
			P(semM);
      printf("\nCHECK 4!\n");
			printf("%c number %d, arrives at %d, enters the bathroom \n", sex, customerNum, time);

			printf("People currently using bathroom: %d\n", *MCurrentUsing);


			if (*numStall == 0)
			{
			 printf("%c number %d is waiting, the size of line: %d \n",sex, customerNum, ((*FCurrentUsing)-x));
      }
                    P(semStall);
                    *numStall -=1;

			printf("%c number %d uses stall\n", sex, customerNum);
			time = ((customerNum * 3) %4 )+1;
			sleep(time);
			*numStall += 1;
			V(semStall);

			P(Stall);
            *MCurrentUsing -=1;
            if((*FCurrentUsing == 0) && (*femalesWaiting > 0))
                {
                    while (*femalesWaiting > 0)
                    {
                        V(semF);
                        *FCurrentUsing +=1;
                        *femalesWaiting -=1;
                    }
                }
                V(Stall);

                printf("%c number %d leaves bathroom\n",sex, customerNum);
                printf("Customers currently inside bathroom: %d\n",*MCurrentUsing);
			}
            else if (sex == 'F')
                {
                    P(Stall);
                    if(*MCurrentUsing + *malesWaiting == 0)
                    {
                        *FCurrentUsing += 1;
                        V(semF);
                    }
                    else
                    {
                        *femalesWaiting +=1;
                    }
                    V(Stall);
                    P(semF);

                    	printf("%c number %d, arrives at %d and enters the bathroom \n", sex, customerNum, time);
                        printf("Customers currently inside bathroom: %d\n", *FCurrentUsing);

                        if(*numStall==0)
                        {
                            printf("%c number %d is waiting, size of waiting line: %d \n",sex, customerNum, *FCurrentUsing-x);
                        }

                    P(semStall);
                    *numStall -=1;
                    printf("%c number %d uses stall\n", sex, customerNum);
                    time = (customerNum * 3) %4+1;
                    sleep(time);
                    *numStall += 1;
                    V(semStall);

                    P(Stall);
                    *FCurrentUsing -=1;
                    if((*FCurrentUsing == 0) && (*malesWaiting > 0))
                        {
                        while (*malesWaiting > 0)
                            {
                            V(semM);
                            *MCurrentUsing +=1;
                            *malesWaiting -=1;
                            }
                        }
                V(Stall);

                printf("%c number %d leaves the bathroom\n",sex, customerNum);
                printf("Customers currently inside bathroom: %d\n",*FCurrentUsing );
                }
                exit(0);
		}
}
customerNum++;

if (r != EOF)
  {
   goto label;
  }

while(1)
{

}


}

void quitHandler (int Quit)
{
    printf("\n%d Females used the bathroom \n", numF);
    printf("%d Males used the bathroom\n", numM);
    printf("Program terminated\n");
    fflush(stdout);
    exit(0);
}
