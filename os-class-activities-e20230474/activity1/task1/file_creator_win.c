/* file_creator_win.c */
/* Compile with MinGW: gcc -o file_creator_win file_creator_win.c  */
/* Or with MSVC:       cl file_creator_win.c                        */

#include <windows.h>
#include <string.h>

int main() {
    const char *text = "Hello from Operating Systems class!\n";
    const char *confirm = "File created successfully!\n";
    DWORD bytesWritten;

    // Create/open the file
    HANDLE hFile = CreateFile(
        "output.txt",           // filename
        GENERIC_WRITE,          // access mode
        0,                      // no sharing
        NULL,                   // default security
        CREATE_ALWAYS,          // always create new (overwrite if exists)
        FILE_ATTRIBUTE_NORMAL,  // normal file
        NULL                    // no template
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        const char *err = "Error creating file\n";
        WriteFile(GetStdHandle(STD_ERROR_HANDLE), err, strlen(err), &bytesWritten, NULL);
        return 1;
    }

    // Write text to the file
    WriteFile(hFile, text, strlen(text), &bytesWritten, NULL);

    // Close the file
    CloseHandle(hFile);

    // Print confirmation to console
    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), confirm, strlen(confirm), &bytesWritten, NULL);

    return 0;
}
