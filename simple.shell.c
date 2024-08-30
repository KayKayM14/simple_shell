#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * display_prompt - display the shell prompt
 */

void display_prompt(void)
{
	printf("CisFun$ ");
	fflush(stdout);
}

/**
 * read_input - Reads a line of input from the standard input.
 *
 * this function uses the getline function to read a line of text
 * from the user. the input  is dynamically allocated and should be free'd
 * after use.
 *
 * Return: a pointer to the string containing the user's input.
 * if the input fails, the program will exit.
 */

char *read_input(void)
{
	char *input = NULL;
	size_t len = 0;
	int getline_status;

	getline_status = getline(&input, &len, stdin);
	if (getline_status == -1) /*fixed assignment in if condition*/
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(0);
		}
		else
		{
			perror("Error reading input");
			exit(1);
		}
	}
	return (input);
}
/**
 * execute_command - Execute a command
 * @input: the command to execute
 */
void execute_command(char *input)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Error forking process");
		exit(1);
	}
	if (pid == 0)
	{
		execl(input, input, (char *)NULL);
		perror("Error executing command");
		printf("./shell: No such file or directory\n");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
/**
 * main - main function that runs the shell in an infinite loop
 * Return: 0 on success
 */

int main(void)
{
	char *input;

	while (1)
	{
		display_prompt();
		input = read_input();
		execute_command(input);
		free(input);
	}
	return (0);
}

