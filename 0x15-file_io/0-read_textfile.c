#include "main.h"
/**
* read_textfile - Reads a text file and prints in POSIX stdout.
* @filename: File 2 read.
* @letters: Number of letter it should read and print.
* Return: Actual number of letter it could read and print.
*/
ssize_t read_textfile(const char *filename, size_t letters) {
    if (!filename) {
        return 0;
    }

    int file = open(filename, O_RDONLY);
    if (file == -1) {
        return 0;
    }

    char *buf = malloc(letters);
    if (!buf) {
        close(file);
        return 0;
    }

    ssize_t read_result = read(file, buf, letters);
    if (read_result == -1) {
        free(buf);
        close(file);
        return 0;
    }

    ssize_t write_result = write(STDOUT_FILENO, buf, read_result);
    free(buf);
    close(file);

    if (write_result == -1 || write_result != read_result) {
        return 0;
    }

    return read_result;
}


