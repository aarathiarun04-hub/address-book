#include <stdio.h>
#include "contact.h"

void list_contacts(struct AddressBook *ab)
{
    if (ab->contactCount == 0)
    {
        printf("No contacts available!\n");
        return;
    }

    printf("\n+++++++++CONTACT LIST+++++++++++\n");
    printf("| No | Name                 | Phone        | Email                     |\n");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < ab->contactCount; i++)
    {
        printf("| %-2d | %-20s | %-12s | %-25s |\n",
               i + 1,
               ab->contacts[i].name,
               ab->contacts[i].phone,
               ab->contacts[i].email);
    }
    printf("===================================\n");
    printf("Total contacts: %d\n", ab->contactCount);
    printf("===================================\n");
}