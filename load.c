#include <stdio.h>
#include "contact.h"

void load_contact(struct AddressBook *ab)
{
    FILE *fp = fopen("database.csv", "r");

    if (fp == NULL)
    {
        printf("No saved contacts found. Starting fresh!\n");
        return;
    }

    ab->contactCount = 0;

    while (ab->contactCount < MAX)
    {
        struct Contact *c = &ab->contacts[ab->contactCount];

        /* CSV format: name,phone,email  (supports names with spaces) */
        if (fscanf(fp, " %49[^,],%14[^,],%49[^\n]",
                   c->name,
                   c->phone,
                   c->email) != 3)
        {
            break;
        }

        ab->contactCount++;
    }

    fclose(fp);

    printf("Done! %d contact(s) loaded.\n", ab->contactCount);
}