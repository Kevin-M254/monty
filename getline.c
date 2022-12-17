#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * getline - getline function
 * @lineptr: blah blah
 * @n: blah blah
 * @file: file
 *
 * Return: getline.
 */
size_t getline(char **lineptr, unsigned int *n, FILE *file)
{
	char *bufptr = NULL;
	char *p = bufptr;
	unsigned int size;
	int c;

	if (lineptr == NULL)
	{ return (-1); }
	if (file == NULL)
	{ return (-1); }
	if (n == NULL)
	{ return (-1); }
	bufptr = *lineptr;
	size = *n;
	c = fgetc(file);
	if (c == EOF)
	{ return (-1); }
	if (bufptr == NULL)
	{ bufptr = malloc(128);
		if (bufptr == NULL)
		{ return (-1); }
		size = 128; }
	p = bufptr;
	while (c != EOF)
	{
		if ((p - bufptr) > (size - 1))
		{
			size = size + 128;
			bufptr = realloc(bufptr, size);
			if (bufptr == NULL)
			{ return (-1); }
			p = bufptr + (size - 128); }
		*p++ = c;
		if (c == '\n')
		{ break; }
		c = fgetc(file);
	}
	*p++ = '\0';
	*lineptr = bufptr;
	*n = size;
	return (p - bufptr - 1);
}
