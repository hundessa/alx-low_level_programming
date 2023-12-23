#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL) {
        dprintf(2, "Error: filename is NULL\n");
        return 0;
    }

    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1) {
        dprintf(2, "Error: Could not open file %s\n", filename);
        return 0;
    }

    char buffer[1024];  // Adjust the buffer size as needed
    ssize_t total_read = 0;
    ssize_t bytes_read;

    while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0 && total_read < letters) {
        ssize_t bytes_to_print = (total_read + bytes_read <= letters) ? bytes_read : letters - total_read;
        ssize_t bytes_written = write(1, buffer, bytes_to_print);

        if (bytes_written != bytes_to_print) {
            dprintf(2, "Error: Write operation failed\n");
            close(file_descriptor);
            return 0;
        }

        total_read += bytes_to_print;
    }

    close(file_descriptor);
    return total_read;
}

int main(int argc, char **argv) {
    ssize_t n;

    if (argc != 2) {
        dprintf(2, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    n = read_textfile(argv[1], 114);
    printf("\n(printed chars: %li)\n", n);

    n = read_textfile(argv[1], 1024);
    printf("\n(printed chars: %li)\n", n);

    return 0;
}
