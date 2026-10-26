#include <stdio.h>
#include "contact.h"
int main()
{
    int choice;
    struct AddressBook ab;
    ab.contactCount = 0;
    load_contact(&ab);
    do
    {
        printf("\n===============Address Book==============\n");
        printf("1.Add contact\n");
        printf("2.Search contact\n");
        printf("3.Edit contact\n");
        printf("4.Delete contact\n");
        printf("5.List contacts\n");
        printf("6.Sort contacts\n");
        printf("7.Save contacts\n");
        printf("8.Exit\n");
        while (1)
        {
            printf("Enter choice: ");
            if (scanf("%d", &choice) == 1)
                break;
            printf("Invalid input! Enter number only(1 to 8)\n");
            while (getchar() != '\n');
        }
        switch(choice)
        {
            case 1: add_contact(&ab); 
            break;
            case 2: search_contact(&ab); 
            break;
            case 3: edit_contact(&ab); 
            break;
            case 4: delete_contact(&ab); 
            break;
            case 5: list_contacts(&ab); 
            break;
            case 6: sort_contacts(&ab); 
            break;
            case 7: save_contact(&ab); 
            break;
            case 8: printf("Thank you!\n"); 
            break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 8);
    return 0;
}