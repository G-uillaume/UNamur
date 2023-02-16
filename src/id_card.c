#include <stdio.h>
#include <stdlib.h>
#include "id_card.h"

id_card_t get_information(int operation)
{
    id_card_t tmp;
    printf("Enter your name: ");
    scanf("%s", tmp.name);
    printf("Enter your first name: ");
    scanf("%s", tmp.first_name);
    if(operation == ADD) {
        printf("Enter your age: ");
        scanf("%s", tmp.age);
    }

    return tmp; 
}

void display_id(id_card_t id_to_print)
{
    printf("\n");
    printf("Name: %s\n", id_to_print.name);
    printf("First name: %s\n", id_to_print.first_name);
    printf("Age: %s\n", id_to_print.age);
}