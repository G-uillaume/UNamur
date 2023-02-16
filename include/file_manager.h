#ifndef FILE_MANAGER_H_
#define FILE_MANAGER_H_

#include "id_card.h"

extern int write_identity(id_card_t id);
extern void read_identities(void);
extern int remove_identity(id_card_t id_to_remove);

#endif