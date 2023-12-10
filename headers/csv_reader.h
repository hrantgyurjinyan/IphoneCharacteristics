#ifndef CSV_READER_H
#define CSV_READER_H

#include "phone_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * @brief Read a phone list from a CSV file and populate a linked list.
 *
 * @param head Pointer to the head of the linked list.
 * @param filename The name of the CSV file to read.
 */
void read_phone_list(struct PhoneNode **head, char *filename);

/**
 * @brief Read a string from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @param buf The buffer to store the read string.
 * @return The number of characters read.
 */
int read_string(int fd, char *buf);

/**
 * @brief Read a number (uint64_t) from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @param number Pointer to store the read number.
 * @return The number of bytes read.
 */
int read_number(int fd, uint64_t *number);

/**
 * @brief Skip a line in a file.
 *
 * @param fd The file descriptor to read from.
 * @return 0 on success, -1 on failure.
 */
int skip_line(int fd);

#endif // CSV_READER_H
