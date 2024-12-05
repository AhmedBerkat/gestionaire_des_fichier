#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

void createFile(const char *filename);
void readFile(const char *filename);
void writeFile(const char *filename, const char *content);
void deleteFile(const char *filename);
void listFiles();

#endif // FILE_OPERATIONS_H
