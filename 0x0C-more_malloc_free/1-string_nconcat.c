#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: amount of bytes.
 *
 * Return: pointer to the allocated memory.
 * if malloc fails, status value is equal to 98.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *sout;
	unsigned int ls1, ls2, lsout, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (ls1 = 0; s1[ls1] != '\0'; ls1++)
		;

	for (ls2 = 0; s2[ls2] != '\0'; ls2++)
		;

	if (n > ls2)
		n = ls2;

	lsout = ls1 + n;

	sout = malloc(lsout + 1);

	if (sout == NULL)
		return (NULL);

	for (i = 0; i < lsout; i++)
		if (i < ls1)
			sout[i] = s1[i];
		else
			sout[i] = s2[i - ls1];

	sout[i] = '\0';

	return (sout);
}

or 
#include "main.h"
#include <stdlib.h>

/**
* string_nconcat - a function that concatenates two strings
* @s1: the first string
* @s2: the second string
* @n: the number of bytes of s2 to be concatenated
* Return: returns a pointer to a new string which contains
* s1 followed by the first n bytes of s2, and a=the null-terminator
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j;
	unsigned int c1 = 0, c2 = 0, c = 0;
	char *str;

	if (s1 != NULL)
		for (i = 0; s1[i] != '\0'; i++)
			c1++;

	if (s2 != NULL)
		for (i = 0; s2[i] != '\0'; i++)
			if (i < n)
				c2++;

	c = c1 + c2 + 1;

	str = malloc(c);
	if (str == NULL)
		return (NULL);

	for (i = 0; i < c1; i++)
		str[i] = s1[i];

	for (j = 0 ; j < c2; i++, j++)
		str[i] = s2[j];
	str[i] = '\0';

	return (str);
}
