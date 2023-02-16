#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_manager.h"

#define FILE_NAME           "./ressources/identity_cards.txt"
#define SEPARATOR           ","
#define NEW_LINE            "\n"
#define LENGHT_MAX          250

static int count_entries(void)
{
    FILE * file;
    char * line = NULL;
    size_t lenght = LENGHT_MAX;
    int lines = 0;

    file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while(getline(&line, &lenght, file) != -1)
    {
        lines++;
    }

    fclose(file);
    return lines;
}

static id_card_t read_identity(int file_line)
{
    FILE * file;
    char * line = NULL;
    size_t lenght = LENGHT_MAX;

    id_card_t id_tmp;
    char *ptr = NULL;

    int counter = 1;

    file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while(counter <= file_line)
    {
        getline(&line, &lenght, file);
        if(counter == file_line) {
            ptr = strtok(line, SEPARATOR);
            memcpy(id_tmp.name, ptr, NAME_SIZE);
            ptr = strtok(NULL, SEPARATOR);
            memcpy(id_tmp.first_name, ptr, NAME_SIZE);
            ptr = strtok(NULL, NEW_LINE);
            memcpy(id_tmp.age, ptr, AGE_SIZE); 
        }
        counter++;
    }

    fclose(file);
    return id_tmp;
}

int write_identity(id_card_t id_to_write)
{
    FILE * file = NULL;
    file = fopen(FILE_NAME, "a");
 
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fputs(id_to_write.name, file);
    fputs(SEPARATOR, file);
    fputs(id_to_write.first_name, file);
    fputs(SEPARATOR, file);
    fputs(id_to_write.age, file);
    fputs(NEW_LINE, file);
    
    fclose(file);
    return 0;
}

void read_identities(void)
{
    int entry;
    for(entry = 1; entry <= count_entries(); entry++)
    {
        display_id(read_identity(entry));
    }
}

int remove_identity(id_card_t id_to_remove)
{
    int counter;
    id_card_t id_read;
    id_card_t * buffer_id;
    int offset = 1;
    int nbr_entries = count_entries();
    
    buffer_id = (id_card_t *) malloc(nbr_entries * sizeof(id_card_t));
    for (counter = 1; counter <= nbr_entries; counter++)
    {
        id_read = read_identity(counter);
        if(!strcmp(id_read.name, id_to_remove.name) && !strcmp(id_read.first_name, id_to_remove.first_name))
        {
            printf("\nThe following person was removed from the register:");
            display_id(id_read);
            offset++;
        }
        else
        {
            buffer_id[counter-offset] = id_read;
        }
    }
    fclose(fopen(FILE_NAME, "w"));
    for(counter=0; counter<=(nbr_entries-offset); counter++)
    {
        write_identity(buffer_id[counter]);
    }

    free(buffer_id);
    return 0;
}