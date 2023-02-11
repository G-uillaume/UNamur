#ifndef __ID_H__
#define __ID_H__

#define MAX_NAME 50

typedef struct User {
    char firstName[MAX_NAME];
    char lastName[MAX_NAME];
    int age;
} User;

void removeNewLine(char *str);
void askId(User *user, int withAge);
void printUser(User *user);
void createUser();
void deleteUser();
void menu();

#endif