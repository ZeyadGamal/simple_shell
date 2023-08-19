#include "shell.h"

/**
 * _getline - reads a line entered from user
 * @lineptr: ptr to buffer
 * @n: size of buffer
 * @fd: file descriptor
 * @mt: pointer to linkedlist
 *
 * Return: number of characters read
 */
ssize_t _getline(char **lineptr, size_t *n, int fd, list_t **mt)
{
	static char *buffer;
	ssize_t buffer_size = BUFFER_SIZE;
	ssize_t chars_read = 0, chars_unread = BUFFER_SIZE / 2, count = 0;

	if (*mt
	buffer = malloc(buffer_size);
	add(mt, NULL, buffer);
	if (!lineptr || !n || !buffer)
		return (-1);
	if (*lineptr)
	{
		buffer = *lineptr;
		buffer_size = *n;
		if (*n == 1)
			chars_unread = 1;
		else
			chars_unread = buffer_size / 2;
	}
	empty_buffer(buffer, buffer_size);
	chars_read = read(fd, buffer + count, chars_unread);
	if (chars_read == -1)
	{
		free(buffer);
		return (-1);
	}
	if (chars_read == 0)
		return (-1);
	chars_read = strlen(buffer);
	count += chars_read;
	if (count > 0)
		if (buffer[count - 1] == '\n')
			chars_read = 0;
	while (chars_read);
	return (count);
}
