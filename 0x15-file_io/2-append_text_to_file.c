#include "main.h"

/**
 * append_text_to_file - function to appends text at the end of a file.
 * @filename: a pointer to name of file
 * @text_content: str to add to the end of file
 *
 * Return: 1 if success or, -1 if failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int outpt, wr, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	outpt = open(filename, O_WRONLY | O_APPEND);
	wr = write(outpt, text_content, l);

	if (outpt == -1 || wr == -1)
		return (-1);

	close(outpt);

	return (1);
}
