#include <stdio.h>
#include <string.h>
#include "contact.h"
int valid_name(char name[])
{
    int i;
    if (strlen(name) == 0)
        return 0;
    for (i = 0; name[i] != '\0'; i++)
    {
        if (!((name[i] >= 'A' && name[i] <= 'Z') ||
              (name[i] >= 'a' && name[i] <= 'z') ||
               name[i] == ' '))
            return 0;
    }
    return 1;
}
int valid_phone(char phone[])
{
    int i;
    if (strlen(phone) != 10)
        return 0;
    for (i = 0; phone[i] != '\0'; i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
            return 0;
    }
    return 1;
}
int valid_email(char email[])
{
    int i, at, dot;
    i = 0; at = 0; dot = 0;
    while (email[i] != '\0')
    {
        if (email[i] == '@')
            at++;
        else if (email[i] == '.')
            dot++;
        else if (!((email[i] >= '0' && email[i] <= '9') ||
                   (email[i] >= 'a' && email[i] <= 'z') ||
                   (email[i] >= 'A' && email[i] <= 'Z')))
            return 0;
        i++;
    }
    if (at == 1 && dot >= 1)
        return 1;
    return 0;
}
int duplicate_phone(struct AddressBook *ab, char phone[])
{
    int i;
    for (i = 0; i < ab->contactCount; i++)
    {
        if (strcmp(ab->contacts[i].phone, phone) == 0)
            return 1;
    }
    return 0;
}

int duplicate_email(struct AddressBook *ab, char email[])
{
    int i;
    for (i = 0; i < ab->contactCount; i++)
    {
        if (strcmp(ab->contacts[i].email, email) == 0)
            return 1;
    }
    return 0;
}
void add_contact(struct AddressBook *ab)
{
    char name[50], phone[15], email[50];
    if (ab->contactCount >= MAX)
    {
        printf("Address book full!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", name);
    if (!valid_name(name))
    {
        printf("Invalid name!\n");
        return;
    }
    printf("Enter phone: ");
    scanf("%s", phone);
    if (!valid_phone(phone))
    {
        printf("Invalid phone!\n");
        return;
    }
    if (duplicate_phone(ab, phone))
    {
        printf("Phone already exists!\n");
        return;
    }
    printf("Enter email: ");
    scanf("%s", email);
    if (!valid_email(email))
    {
        printf("Invalid email!\n");
        return;
    }
    if (duplicate_email(ab, email))
    {
        printf("Email already exists!\n");
        return;
    }
    strcpy(ab->contacts[ab->contactCount].name, name);
    strcpy(ab->contacts[ab->contactCount].phone, phone);
    strcpy(ab->contacts[ab->contactCount].email, email);
    ab->contactCount++;
    printf("Contact added!\n");
}