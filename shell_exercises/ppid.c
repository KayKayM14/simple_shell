#include <stdio.h>
#include  <unistd.h> /*needed for getppid*/

int main(void)
{
	pid_t ppid; /*declare a variable to store the ppid*/

	ppid = getppid(); /*get the Parent Process ID*/

	printf("Parent Process ID (PPID): %d\n", ppid);

	return (0); /*exit the program*/
}
