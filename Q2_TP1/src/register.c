#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "include/register.h"
#include "include/linked_list.h"

void registerUser(User *user) {
    FILE *f = fopen("src/data.txt", "a");
	if (f == NULL) {
		printf("File could not be opened\n");
	} else {
		fprintf(f, "%s %s %d\n", user->lastName, user->firstName, user->age);
		fclose(f);
	}
}

void readRegister(int sorted) {
    char firstName[MAX_NAME];
	char lastName[MAX_NAME];
	int age;
    int i = 0;

	FILE *f;
    if (sorted) {
        f = fopen("src/data_sorted.txt", "r");
    } else {
	    f = fopen("src/data.txt", "r");
    }
	if (f == NULL) {
		printf("File could not be opened\n");
	} else {
		printf("%-13s%-13s%s\n", "Last Name", "First Name", "Age");
        printf("%-30s\n", "================================");
		fscanf(f, "%s%s%d", lastName, firstName, &age);
		while (!feof(f)) {
			printf("%d: %-13s%-13s%d yo\n", i, lastName, firstName, age);
			fscanf(f, "%s%s%d", lastName, firstName, &age);
            i++;
		}
		fclose(f);
	}
}

void sortRegister() {
    List *l = initList();

    FILE *f;
	f = fopen("src/data.txt", "r");
    if (f == NULL) {
		printf("File could not be opened\n");
	} else {
        User *user = malloc(sizeof(*user));
        if (user == NULL) exit(EXIT_FAILURE);
        while (!feof(f)) {
            fscanf(f, "%s%s%d", user->lastName, user->firstName, &user->age);
            if (l->length == 0 || (strcmp(l->last->user.lastName, user->lastName) != 0 || strcmp(l->last->user.firstName, user->firstName) != 0)) {
                push(l, *user);
            }
        }
        free(user);
		fclose(f);
	}

    quickSort(l);

    f = fopen("src/data_sorted.txt", "w");
    if (f == NULL) {
        printf("File could not be opened\n");
    } else {
        int i;
        Element *el = l->first;
        for (i = 0; i < l->length; i++) {
            fprintf(f, "%s %s %d\n", el->user.lastName, el->user.firstName, el->user.age);
            el = el->next;
        }
        fclose(f);
    }

    delList(l);
}