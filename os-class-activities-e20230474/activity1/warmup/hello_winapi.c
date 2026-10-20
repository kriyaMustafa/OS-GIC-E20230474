/* hello_winapi.c */
/* Compile with MinGW: gcc -o hello_winapi hello_winapi.c        */
/* Or with MSVC:       cl hello_winapi.c                          */

#include <windows.h>
#include <string.h>

int main() {
    const char *message = "Hello, Windows API!\n";
    DWORD bytesWritten;

    // Write to the console (STD_OUTPUT_HANDLE is stdout)
    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), message, strlen(message), &bytesWritten, NULL);

    return 0;
}
