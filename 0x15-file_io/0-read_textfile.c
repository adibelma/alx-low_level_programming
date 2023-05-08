#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads text file and prints it to POSIX stdout
 * @filename: text to the file to read and print
 * @letters: number of letters bytes to read
 * Return: actual number of bytes it coulls read and printed
 *        0 when function can't be openeds
 *        0 when filename is NULL
 *        0 if write fails or doesn't write expected amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *b;
	ssize_t f;
	ssize_t wr;
	ssize_t txt;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	b = malloc(sizeof(char) * letters);
	txt = read(f, b, letters);
	wr = write(STDOUT_FILENO, b, txt);

	free(b);
	close(f);
	return (wr);
}
