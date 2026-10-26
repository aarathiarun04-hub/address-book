#include <stdio.h>
#include <string.h>
#include "contact.h"

void delete_contact(struct AddressBook *ab)
{
    int i, index, choice;
    index = -1;

    if (ab->contactCount == 0)
    {
        printf("No contacts!\n");
        return;
    }

    printf("Delete by:\n1. Name\n2. Phone\n3. Email\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        char name[50];
        printf("Enter name: ");
        scanf(" %[^\n]", name);

        for (i = 0; i < ab->contactCount; i++)
        {
            if (strcmp(ab->contacts[i].name, name) == 0)
            {
                index = i;
                break;
            }
        }
    }
    else if (choice == 2)
    {
        char phone[15];
        printf("Enter phone: ");
        scanf("%s", phone);

        for (i = 0; i < ab->contactCount; i++)
        {
            if (strcmp(ab->contacts[i].phone, phone) == 0)
            {
                index = i;
                break;
            }
        }
    }
    else if (choice == 3)
    {
        char email[50];
        printf("Enter email: ");
        scanf("%s", email);

        for (i = 0; i < ab->contactCount; i++)
        {
            if (strcmp(ab->contacts[i].email, email) == 0)
            {
                index = i;
                break;
            }
        }
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    if (index == -1)
    {
        printf("Contact not found!\n");
        return;
    }

    for (i = index; i < ab->contactCount - 1; i++)
        ab->contacts[i] = ab->contacts[i + 1];

    ab->contactCount--;
    printf("Contact deleted!\n");
}