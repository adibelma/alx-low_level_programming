#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *make_buffers(char *file);
void cl_f(int f);

/**
 * make_buffers - asign 1024 bytes for buffer.
 * @file: Name of buffer file is storing chars.
 *
 * Return: a ptr to the new assign buffer.
 */
char *make_buffers(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * cl_f - function is closes files descriptors.
 * @f: file descriptor to close.
 */
void cl_f(int f)
{
	int c;

	c = close(f);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f);
		exit(100);
	}
}

/**
 * main - copie the content filr to another.
 * @argc: number of argument.
 * @argv: array of ptr to arguments.
 *
 * Return: 0 if (Success)
 *
 * Description: if the argument is incorrect, then exit with code 97 and print something.
 *              if file_from doesn't exist, or if we cannot read it, exit code 98 and print something.
 *              if file_to can not creat, exit code 99 and print something.
 *              if file discriptor cannot be closed, exit code 100 and print something.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = make_buffers(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		w = write(to, buff, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		r = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buff);
	cl_f(from);
	cl_f(to);

	return (0);
}
