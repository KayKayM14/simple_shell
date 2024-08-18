#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TOKEN 100 /*number of tokens*/

char **split_string(const char *str, const char *delim, int *num_tokens)
{
	char **tokens = malloc(MAX_TOKEN * sizeof(char *));
	char *str_cpy = strdup(str); /*dup the str to avoid modifying orig*/
	char *start = str_cpy;
	char *the_end;
	int count = 0;

/*get the entire string*/
	while (*start != '\0')
	{
/*find where the delimeter is (eg: , space*/
	the_end = strpbrk(start, delim);
	if (the_end == NULL)
	{
		/*if no delim found, go to end of string*/
		the_end = start + strlen(start);
	}
	/*if there is a word between start and end, cpy it*/
	if (the_end > start)
	{
		/*memory of the word*/
		tokens[count] = malloc(the_end - start + 1);
		/*cpy the str*/
		strncpy(tokens[count], start, the_end - start);
		/*add NULL char to end the word*/
		tokens[count][the_end - start] = '\0';
		count++;
	}
	start = the_end + 1; /*move to the next part of the str*/
	}
	tokens[count] = NULL; /*mark the end of str*/
	*num_tokens = count; /*store how many words was found*/
	free(str_cpy); /*free copied string*/
	return (tokens); /*return list of words*/
}

int main(void)
{
	char input[] = "This is the challenge";
	char **tokens;
	int num_tokens, i;
/*split input string into words*/
	tokens = split_string(input, " ",&num_tokens);

	/*print each word*/
	for (i = 0; i < num_tokens; i++)
	{
		printf("Token %d: %s\n", i, tokens[i]);
		free(tokens[i]); /*free mem for each word*/
	}
	free(tokens); /*free list of words*/

	return (0);
}
