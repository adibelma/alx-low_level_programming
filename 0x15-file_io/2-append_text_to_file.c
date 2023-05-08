#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of file
 * @filename: a pointer to the file
 * @text_content: the string to add at the end of file
 *
 * Return: 1 if (Success), or -1 if (Failure)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int oupt, wr, ln = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (ln = 0; text_content[ln];)
			ln++;
	}

	oupt = open(filename, O_WRONLY | O_APPEND);
	wr = write(oupt, text_content, ln);

	if (oupt == -1 || wr == -1)
		return (-1);

	close(oupt);

	return (1);
}
