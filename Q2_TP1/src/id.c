#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "include/id.h"
#include "include/linked_list.h"
#include "include/register.h"

void removeNewLine(char *str) {
    char *ptr = strchr(str, '\n');
    if (ptr) {
        // if new line found replace with null character
        *ptr = '\0';
    }
}

void askId(User *user, int withAge) {
    printf("Enter your last name: ");
    fgets(user->lastName, MAX_NAME, stdin);
    removeNewLine(user->lastName);
    printf("Enter your first name: ");
    fgets(user->firstName, MAX_NAME, stdin);
    removeNewLine(user->firstName);
    if (withAge) {
        printf("Enter your age: ");
        scanf("%d", &user->age);
    }
}

void printUser(User *user) {
    printf("%s %s - %dy\n", user->lastName, user->firstName, user->age);
}

void createUser() {
    User *user = malloc(sizeof(*user));
    if (user == NULL) exit (EXIT_FAILURE);
    askId(user, 1);
    registerUser(user);
    sortRegister();
    printf("Thanks!\n");
    free(user);
}

void deleteUser() {
    User *user = malloc(sizeof(*user));
    if (user == NULL) {
        exit(EXIT_FAILURE);
    }

    askId(user, 0);

    List *l = initList();

    FILE *f;
	f = fopen("src/data.txt", "r");
    if (f == NULL) {
		printf("File could not be opened\n");
	} else {
        User *tmp = malloc(sizeof(*tmp));
        do {
            fscanf(f, "%s%s%d", tmp->lastName, tmp->firstName, &tmp->age);
            push(l, *tmp);
        } while (!feof(f));
        free(tmp);
		fclose(f);
	}

    int index = findIndex(l, user);
    if (index >= 0) del(l, index);

    f = fopen("src/data.txt", "w");
    if (f == NULL) {
        printf("File could not be opened\n");
    } else {
        int i;
        Element *el = l->first;
        for (i = 0; i < l->length - 1; i++) {
            fprintf(f, "%s %s %d\n", el->user.lastName, el->user.firstName, el->user.age);
            el = el->next;
        }
        fclose(f);
    }

    delList(l);

    free(user);
}

void menu() {
    int res;
    do {
        printf("1. View register\n2. Add a user\n3. Delete a user\n4. Quit\n");
        scanf("%d", &res);
        getchar();
        switch (res) {
            case 1: {
                int res2;
                printf("1. Sorted\n2. Not sorted\n");
                do {
                    scanf("%d", &res2);
                    switch(res2) {
                        case 1: {
                            readRegister(1);
                            break;
                        }
                        case 2: {
                            readRegister(0);
                            break;;
                        } default: {
                            printf("Wrong choice\n");
                        }
                    }
                } while (res2 < 1 || res2 > 2);
                break;
            }
            case 2: {
                createUser();
                break;
            }
            case 3: {
                deleteUser();
                break;
            }
            case 4: {
                printf("Exit\n");
                exit(EXIT_SUCCESS);
            }
            default: {
                printf("Wrong choice\n");
            }
        }
    } while (1);
}