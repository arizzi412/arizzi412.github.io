//Read, parse, fork , execute
#include <stdio.h>
#include<unistd.h>


int parse(char *  input, char ** argv)
{
	int x = 0; // variable to indicate presence of an '&'. 0 means there isnt.

	while(*input != '\0')
	{

		while(*input == ' ' || *input == '\n')  // replaces spaces and newlines with null characters.
		{
			*input++  = '\0';

		}
		if (*input == '&') { x = 1; *input='\0';}  // checks for ampersand.
		if (*input  == '\0') {break;}    // end of file

		*argv++ = input;  //place first character of command into array.
		while(*input != ' ' && *input != '\n' && *input != '\0')
		{
			input++;
		}
	}
	*argv =  NULL;
 return x;
}

void execute(char** argv, int x)
{
	pid_t pid;
	pid = fork();
	int waitstatus;
  if (pid == 0)
	{
		execvp(*argv, argv);
	}

	else
	{
		if (x == 0) // checks for ampersand.
		{
			wait(waitstatus);
		}
	}
}

int main()
{
int keepgoing = 1;
int ampersand;
char input[999];
char *argv[20];
while (keepgoing == 1)
{

printf("Shell: ");
gets(input);
printf("\n");
ampersand = parse(input, argv);
execute(argv, ampersand);

}
return 0;
}
