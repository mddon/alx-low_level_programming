#include "main.h"

/**
 * append_text_to_file - this program appends text at the end of a file
 * @filename: this is the filename.
 * @text_content: added content.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int f_describe;
	int k_letters;
	int rewrite_byte;

	if (!filename)
		return (-1);

	f_describe = open(filename, O_WRONLY | O_APPEND);

	if (f_describe == -1)
		return (-1);

	if (text_content)
	{
		for (k_letters = 0; text_content[k_letters]; k_letters++)
			;

		rewrite_byte = write(f_describe, text_content, k_letters);

		if (rewrite_byte == -1)
			return (-1);
	}

	close(f_describe);

	return (1);
}
