#include "main.h"

/**
 * create_file - function to creates files
 * @filename: pointer to the name of the file to be created.
 * @text_content: pointer to a string of the file to be writted.
 *
 * Return: 1 (Success), or -1 (Failure)
 */
int create_file(const char *filename, char *text_content)
{
	int wr, f, ln = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (ln = 0; text_content[ln];)
			ln++;
	}

	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(f, text_content, ln);

	if (f == -1 || wr == -1)
		return (-1);

	close(f);

	return (1);
}
