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
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
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
 * main - Function is copies contents of a file to another.
 * @argc: Number of arguments supply to program.
 * @argv: Array of ptr to arguments.
 *
 * Return: 0 if success.
 *
 * Description: exit with code 97 if the argument count is not correct.
 *              exit with code 98 if file_from doesn't exist or cannot read it.
 *              exit with code 99 if file_to cannot be created or write to.
 *              exit with code 100 if descriptor file cannot be closed.
 */
int main(int argc, char *argv[])
{
	int frm, too, ipt_r, opt_w;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = make_buffers(argv[2]);
	frm = open(argv[1], O_RDONLY);
	ipt_r = read(frm, buf, 1024);
	too = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (frm == -1 || ipt_r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		opt_w = write(too, buf, ipt_r);
		if (too == -1 || opt_w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		ipt_r = read(frm, buf, 1024);
		too = open(argv[2], O_WRONLY | O_APPEND);

	} while (ipt_r > 0);

	free(buf);
	cl_f(frm);
	cl_f(too);

	return (0);
}
