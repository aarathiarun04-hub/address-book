# Address Book

A menu-driven address book written in C. Contacts live in a fixed-size array of
structs and are persisted to a plain `database.csv` file, so nothing is lost when
the program exits.

## Features

- **Add** a contact with validation for name, phone number and email address
- **Search** a contact by name
- **Edit** an existing contact in place
- **Delete** a contact
- **List** every saved contact
- **Sort** contacts by name or by phone number
- **Save / load** contacts to and from `database.csv`
- Rejects duplicate phone numbers and duplicate email addresses
- Safe input handling — non-numeric menu input is discarded instead of
  breaking the loop
- Capacity of 100 contacts (`MAX` in `contact.h`)

## Build & run

```sh
gcc -o addressbook *.c
./addressbook          # addressbook.exe on Windows
```

## Menu

```
===============Address Book==============
1.Add contact
2.Search contact
3.Edit contact
4.Delete contact
5.List contacts
6.Sort contacts
7.Save contacts
8.Exit
```

Contacts are loaded from `database.csv` at startup. Changes made in memory are
written to disk only when you pick option **7. Save contacts**.

## Project structure

| File | Purpose |
| --- | --- |
| `contact.h` | `Contact` / `AddressBook` structs and function prototypes |
| `main.c` | Driver: menu loop and input validation |
| `add.c` | Add a contact (with validation + duplicate checks) |
| `search.c` | Search by name |
| `edit.c` | Edit name / phone / email of a contact |
| `delete.c` | Remove a contact |
| `display.c` | List all contacts |
| `sort.c` | Sort by name or phone |
| `save.c` | Write contacts to `database.csv` |
| `load.c` | Read contacts back from `database.csv` |
| `database.csv` | Sample data (`name,phone,email` per line) |

## Data format

```
arjun,1234567899,arh@gmail.com
arun,5555555555,arun@gmail.com
```

One contact per line — the name field may contain spaces.
