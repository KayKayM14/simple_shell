#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*for write function*/

#define PROMPT "$" /*define prompt string*/

/**
 * main - main function
 *
 * Return: 0 (success)
 */

int main(void)
{
	char *input = NULL; /*pointer to store the input line*/
	size_t buf_len = 0; /*size of buffer in bytes*/
	ssize_t char_read; /*number of characterss read*/

/**
 * this prints the prompt of the user
 * write: prints the prompt
 * STDOUT_FILENO: is 1 (fie descriptor fr standard output)
 * PROMPT: variable that holds data to be written
 * 2: number of bytes (characters) to write
 */
	write(STDOUT_FILENO, PROMPT, 2);
/**
 * read a line from standard input
 * getline: read a full line of text from input
 * &input: pointer to where the line will be stored
 * (allocated or reallocated as needed)
 * &len: size of the allocated buffer for 'line'
 * stdin: source of input (usually keyboard)
 */
	char_read = getline(&input, &buf_len, stdin);

/**
 * check if reading was successful
 * read != -1: check the getline was successful in reading a line
 * if read is not -1 , it means the reading was successful
 * and the input line can be printed.
 * Handling -1: if getline return -1, it means there was an
 * issue (like an error or EOF) and you might want to handle
 * this case by displaying an error message or exiting the program)
 */
	if (char_read == -1)
	{
		perror("Error reading input"); /*print error*/
		free(input); /*free allocated mem*/
		return (1); /*exit with error code*/
	}

	printf("You entered %s\n", input);
	free(input); /*free allocated memory*/

	/*exit successfully*/
	return (0);
}
