#include <stdio.h>
#include "contact.h"
void save_contact(struct AddressBook *ab)
{
    FILE *fp = fopen("database.csv", "w");
    if (fp == NULL)
    {
        printf("Error: Could not open file for saving.\n");
        return;
    }
    for (int i = 0; i < ab->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
                ab->contacts[i].name,
                ab->contacts[i].phone,
                ab->contacts[i].email);
    }
    fclose(fp);
    printf("%d contact(s) saved successfully!\n", ab->contactCount);
}