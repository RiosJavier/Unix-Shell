/* 
NAME : _Javier Rios_
CS 4350 – 251 - Unix Systems Programming
Assignment Number: _6_
Due Date: 4 / 10 / 2023

This program performs various system and file manipulations using system commands.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void createFile() {
    system("touch INPUT-1-PA6.txt");
    printf("1. INPUT-1-PA6.txt\n");
}

void displayPermissionsBefore() {
    printf("2. File permission status is:\n");
    system("ls -l INPUT-1-PA6.txt");
}

void changeFileMode() {
    system("chmod 700 INPUT-1-PA6.txt");
    printf("3. File mode is changed.\n");
}

void displayPermissionsAfter() {
    printf("4. File permission status is:\n");
    system("ls -l INPUT-1-PA6.txt");
}

void appendText() {
    system("echo 'UNIX PROGRAMMING' >> INPUT-1-PA6.txt");
    system("echo 'EXERCISE USING FEW SYSTEMS COMMANDS' >> INPUT-1-PA6.txt");
    system("echo 'BY HUSAIN GHOLOOM' >> INPUT-1-PA6.txt");
    printf("5. Text is appended to the file.\n");
}

void closeFile() {
    // In C using system commands, closing a file this way is implicit.
    printf("6. The file is closed.\n");
}

void displayFileContent() {
    printf("7. Content of the input file:\n");
    system("cat INPUT-1-PA6.txt");
}

void displayDateTime() {
    printf("8. Current date and time is:\n");
    system("date");
}

void displayLastAccessTime() {
    printf("9. Time of last file access:\n");
    system("stat -c '%x' INPUT-1-PA6.txt");
}

void displaySystemInfo() {
    printf("10. System name:\n");
    system("uname -s");
    printf("11. Local host name:\n");
    system("hostname");
    printf("12. Host name:\n");
    system("hostname");
    printf("13. The process id:\n");
    printf("%d\n", getpid());
    printf("14. Parent process id:\n");
    printf("%d\n", getppid());
    printf("15. Priority level of the process:\n");
    system("nice");
}

void displayFileInfo() {
    printf("16. The file Name is:\n");
    printf("INPUT-1-PA6.txt\n");
    printf("17. The device is:\n");
    system("stat -c '%d' INPUT-1-PA6.txt");
    printf("18. The inode is:\n");
    system("stat -c '%i' INPUT-1-PA6.txt");
    printf("19. The file protection:\n");
    system("stat -c '%a' INPUT-1-PA6.txt");
    printf("20. Owner’s user ID:\n");
    system("stat -c '%u' INPUT-1-PA6.txt");
    printf("21. Owner’s group ID:\n");
    system("stat -c '%g' INPUT-1-PA6.txt");
    printf("22. Owner’s effective user ID:\n");
    printf("%d\n", geteuid());
    printf("23. Size of INPUT-1-PA6.txt file:\n");
    system("stat -c '%s' INPUT-1-PA6.txt");
    printf("24. Block size of INPUT-1-PA6.txt file:\n");
    system("stat -c '%o' INPUT-1-PA6.txt");
    printf("25. Number of blocks allocated to INPUT-1-PA6.txt file:\n");
    system("stat -c '%b' INPUT-1-PA6.txt");
}

void appendAndRenameFile() {
    system("echo 'Almost Over.' >> INPUT-1-PA6.txt");
    printf("26. A new text is appended to INPUT-1-PA6.txt file.\n");
    printf("27. Redisplaying the content of INPUT-1-PA6.txt file.\n");
    system("cat INPUT-1-PA6.txt");
    system("mv INPUT-1-PA6.txt INPUT-2-PA6.txt");
    printf("28. Renamed The file to be INPUT-2-PA6.txt.\n");
    printf("29. The content of the new INPUT-2-PA6.txt file:\n");
    system("cat INPUT-2-PA6.txt");
}

void transformContent() {
    printf("30. changing all small letters to capital letters and vice versa to a new file INPUT-3-PA6.txt");
    system("tr 'a-zA-Z' 'A-Za-z' < INPUT-2-PA6.txt > INPUT-3-PA6.txt");
    printf("31. The content of the new INPUT-3-PA6.txt file:\n");
    system("cat INPUT-3-PA6.txt");
}

void removeAndCheck() {
    system("rm INPUT-3-PA6.txt");
    printf("32. Removed INPUT-3-PA6.txt files from current Directory.\n");
    printf("33. Displaying the content of INPUT-3-PA6.txt file.\n");
    system("cat INPUT-3-PA6.txt");
}
void printFooter() {
    printf("\nApril – 2024\nJavier Rios\n");
}


int main() {
    createFile();
    displayPermissionsBefore();
    changeFileMode();
    displayPermissionsAfter();
    appendText();
    closeFile();
    displayFileContent();
    displayDateTime();
    displayLastAccessTime();
    displaySystemInfo();
    displayFileInfo();
    appendAndRenameFile();
    transformContent();
    removeAndCheck();
    printFooter();
    return 0;
}
