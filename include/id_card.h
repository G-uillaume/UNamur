#ifndef ID_CARD_H_
#define ID_CARD_H_

#define NAME_SIZE               25
#define AGE_SIZE                3
#define REMOVE                  1
#define ADD                     0

typedef struct identity_card
{
    char name[NAME_SIZE];
    char first_name[NAME_SIZE];
    char age[AGE_SIZE]; 
} id_card_t;

extern void display_id(id_card_t id_to_print);
extern id_card_t get_information(int operation);


#endif