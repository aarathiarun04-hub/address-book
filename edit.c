#include <stdio.h>
#include <string.h>
#include "contact.h"

void edit_contact(struct AddressBook *ab)
{
    int i, index, choice;
    index = -1;

    if (ab->contactCount == 0)
    {
        printf("No contacts!\n");
        return;
    }

    printf("Search by:\n1. Name\n2. Phone\n3. Email\n");
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
        printf("Invalid choice\n");
        return;
    }

    if (index == -1)
    {
        printf("Contact not found\n");
        return;
    }

    printf("Found: %s %s %s\n", ab->contacts[index].name, ab->contacts[index].phone, ab->contacts[index].email);

    char newphone[15], newemail[50];

    printf("Enter new phone: ");
    scanf("%s", newphone);
    if (!valid_phone(newphone))
    {
        printf("Invalid phone!\n");
        return;
    }
    if (duplicate_phone(ab, newphone))
    {
        printf("Phone already exists!\n");
        return;
    }

    printf("Enter new email: ");
    scanf("%s", newemail);
    if (!valid_email(newemail))
    {
        printf("Invalid email!\n");
        return;
    }
    if (duplicate_email(ab, newemail))
    {
        printf("Email already exists!\n");
        return;
    }

    strcpy(ab->contacts[index].phone, newphone);
    strcpy(ab->contacts[index].email, newemail);
    printf("Contact updated!\n");
}