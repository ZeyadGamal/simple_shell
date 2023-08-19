#include "shell.h"

/**
 * empty_buffer - empties the buffer
 * @buffer: pointer to buffer
 * @buffer_size: size of buffer
 */
void empty_buffer(char *buffer, ssize_t buffer_size)
{
	ssize_t i = 0;

	while (i < buffer_size)
		buffer[i++] = '\0';
}
