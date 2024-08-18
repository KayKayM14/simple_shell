#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*for the write function*/

#define PROMPT "$" /*define the prompt string*/

int main(void)
{       
        char *line = NULL; /*pointer to store the input line*/
        size_t len = 0; /*size of the buffer*/
        ssize_t read; /*number of characters read*/

/*this prints the "$" to the terminal*/

	/*print the prompt*/
	write(STDOUT_FILENO, PROMPT, 2);

/*read line of input from user*/
/*dynamically allocates memory for line if needd and  stores input*/

	/*read a line of input from stdin*/
	read = getline(&line, &len, stdin);

	/*check if reading was successful*/
	if (read != -1)
	{
		/*print the input line*/
		printf("%s", line);
	}
	/*free the allocated memory*/ 
	free(line);

	return (0);
}
