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
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int frm, too, ipt_r, opt_w;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = make_buffers(argv[2]);
	frm = open(argv[1], O_RDONLY);
	ipt_r = read(frm, buff, 1024);
	too = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (frm == -1 || ipt_r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		opt_w = write(too, buff, ipt_r);
		if (too == -1 || opt_w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		ipt_r = read(frm, buff, 1024);
		too = open(argv[2], O_WRONLY | O_APPEND);

	} while (ipt_r > 0);

	free(buff);
	cl_f(frm);
	cl_f(too);

	return (0);
}
