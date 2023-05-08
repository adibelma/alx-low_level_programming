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
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
