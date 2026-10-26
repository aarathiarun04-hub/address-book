#include <stdio.h>
#include <string.h>
#include "contact.h"

void search_contact(struct AddressBook *ab)
{
    char name[50];
    int i, found;
    found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    for (i = 0; i < ab->contactCount; i++)
    {
        if (strcmp(ab->contacts[i].name, name) == 0)
        {
            printf("Name  : %s\n", ab->contacts[i].name);
            printf("Phone : %s\n", ab->contacts[i].phone);
            printf("Email : %s\n", ab->contacts[i].email);
            printf("---------------------------------\n");
            found = 1;
        }
    }
    if (!found)
        printf("Contact not found!\n");
}