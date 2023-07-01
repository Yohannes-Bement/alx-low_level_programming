#include <stdio.h>





 void first(void) __attribute__ ((constructor));

/**
 


 
 *
 
 * First - after the main printed  a sentence
 
 *
 
 * Function  Is Executed
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

