#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. If it fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int file_descriptor;
    ssize_t num_bytes_read, num_bytes_written;
    char *buffer;

    if (!filename)
        return (0);

    file_descriptor = open(filename, O_RDONLY);

    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (!buffer)
        return (0);

    num_bytes_read = read(file_descriptor, buffer, letters);
    num_bytes_written = write(STDOUT_FILENO, buffer, num_bytes_read);

    close(file_descriptor);

    free(buffer);

    return (num_bytes_written);
}
