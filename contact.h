#ifndef CONTACT_H
#define CONTACT_H

#define MAX 100

struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
};

struct AddressBook
{
    struct Contact contacts[MAX];
    int contactCount;
};

void add_contact(struct AddressBook *ab);
void search_contact(struct AddressBook *ab);
void edit_contact(struct AddressBook *ab);
void delete_contact(struct AddressBook *ab);
void list_contacts(struct AddressBook *ab);
void sort_contacts(struct AddressBook *ab);
void load_contact(struct AddressBook *ab);
void save_contact(struct AddressBook *ab);
int valid_name(char name[]);
int valid_phone(char phone[]);
int valid_email(char email[]);
int duplicate_phone(struct AddressBook *ab, char phone[]);
int duplicate_email(struct AddressBook *ab, char email[]);

#endif