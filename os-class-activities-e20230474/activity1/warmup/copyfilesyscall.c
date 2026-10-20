/* copyfilesyscall.c */
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[1024];
    ssize_t bytesRead;

    // Open source file for reading
    int src = open("result.txt", O_RDONLY);
    if (src < 0) {
        const char *err = "Error: cannot open result.txt\n";
        write(2, err, 30);  // fd 2 = stderr
        return 1;
    }

    // Create/open destination file for writing (create if not exists, truncate if exists)
    int dst = open("copyresult.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst < 0) {
        const char *err = "Error: cannot create copyresult.txt\n";
        write(2, err, 36);
        close(src);
        return 1;
    }

    // Read from source and write to destination, chunk by chunk
    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        write(dst, buffer, bytesRead);
    }

    // Close both files
    close(src);
    close(dst);

    const char *msg = "File copied successfully!\n";
    write(1, msg, 25);  // Print confirmation to terminal
    return 0;
}
