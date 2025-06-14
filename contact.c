//
// Created by savel on 14/06/2025.
//

#include "contact.h"

#include <stdlib.h>

Contact * create_contact(String *name, String *email, int age) {
    Contact *contact = malloc(sizeof(Contact));
    contact->name = name;
    contact->email = email;
    contact->age = age;
    return contact;
}

void print_contact(const Contact *contact) {
    printf("Contact\n");
    print(contact->name);
    print(contact->email);
    printf("%d\n", contact->age);
}

void destroy_contact(Contact *contact) {
    destroy_string(contact->name);
    destroy_string(contact->email);
    free(contact);
}

void print_all_contacts(Contact **contacts, int count) {
    for (int i = 0; i < count; i++) {
        printf("Contact number %d:\n", i);
        print_contact(contacts[i]);
    }
}
