#include <stdlib.h>
#include <stdio.h>

#include "include/functions.h"

int main(int arc, char *argv[]) {
    printf("=====================\nAPPELLE DE LA FONCTION ALPHA\n=====================\n");
    char *alpha_string = malloc(0);

    alpha(alpha_string);

    printf("%s\n", alpha_string);

    printf("=====================\nAPPELLE DE LA FONCTION BETA\n=====================\n");
    printf("beta: %s\n", beta());
    free(alpha_string);


    printf("=====================\nAPPELLE DE LA FONCTION DYNAMIC_ARRAY\n=====================\n");
    dynamic_array();
    printf("=====================\nAPPELLE DE LA FONCTION DYNAMIC_LINKED_LIST\n=====================\n");
    dynamic_linked_list();
    return EXIT_SUCCESS;
}