#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - print name using point to func
 * @name: add to string 
 * @f: pointer to function
 * Return: success
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

