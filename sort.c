#include <stdio.h>
#include <string.h>
#include "contact.h"

static void sort_by_name(struct AddressBook *ab)
{
    struct Contact temp;

    for (int i = 0; i < ab->contactCount - 1; i++)
        for (int j = i + 1; j < ab->contactCount; j++)
            if (strcmp(ab->contacts[i].name, ab->contacts[j].name) > 0)
            {
                temp = ab->contacts[i];
                ab->contacts[i] = ab->contacts[j];
                ab->contacts[j] = temp;
            }
}

static void sort_by_phone(struct AddressBook *ab)
{
    struct Contact temp;

    for (int i = 0; i < ab->contactCount - 1; i++)
        for (int j = i + 1; j < ab->contactCount; j++)
            if (strcmp(ab->contacts[i].phone, ab->contacts[j].phone) > 0)
            {
                temp = ab->contacts[i];
                ab->contacts[i] = ab->contacts[j];
                ab->contacts[j] = temp;
            }
}

static void sort_by_email(struct AddressBook *ab)
{
    struct Contact temp;

    for (int i = 0; i < ab->contactCount - 1; i++)
        for (int j = i + 1; j < ab->contactCount; j++)
            if (strcmp(ab->contacts[i].email, ab->contacts[j].email) > 0)
            {
                temp = ab->contacts[i];
                ab->contacts[i] = ab->contacts[j];
                ab->contacts[j] = temp;
            }
}

// public function
void sort_contacts(struct AddressBook *ab)
{
    int ch;

    printf("\nSort by:\n1. Name\n2. Phone\n3. Email\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1: sort_by_name(ab); break;
        case 2: sort_by_phone(ab); break;
        case 3: sort_by_email(ab); break;
        default: printf("Invalid choice!\n");
    }
}