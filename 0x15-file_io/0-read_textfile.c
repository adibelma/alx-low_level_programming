#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads text file and print it to stdout POSIX
 * @filename: text file to read and print
 * @letters: letters to be printed
 * Return: The actual number of bytes it could read and print
 *        0 if file can't be opened or read
 *        0 if filename is NULL
 *        0 if write fails or doesn't write the expected amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t f;
	ssize_t wr;
	ssize_t txt;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	txt = read(f, buff, letters);
	wr = write(STDOUT_FILENO, buff, txt);

	free(buff);
	close(f);
	return (wr);
}
