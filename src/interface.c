#include <stdio.h>
#include <stdlib.h>
#include "id_card.h"
#include "file_manager.h"
#include "interface.h"

static void display_menu(void)
{
    printf("=========== ID MENU ===========\n");
    printf(".0: Add a new person\n");
    printf(".1: Display the list of persons\n");
    printf(".2: Remove a person\n");
    printf(".3: Exit\n");
    printf("===============================\n");
    printf("Make a selection: ");
}

void menu(void)
{
    int option_selection;

    display_menu();
    scanf("%d", &option_selection);
    switch (option_selection)
    {
    case 0:
        write_identity(get_information(ADD));
        break;
    
    case 1:
        read_identities();
        break;
    
    case 2:
        remove_identity(get_information(REMOVE));
        break;
    
    case 3:
        exit(EXIT_SUCCESS);
    
    default:
        printf("Option doesn't existe !\n");
        break;
    }
}