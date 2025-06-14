//
// Created by savel on 14/06/2025.
//

#ifndef CONTACT_H
#define CONTACT_H
#include "string.h"

typedef struct Contact Contact;

struct Contact {
    String *name;
    String *email;
    int age;
};

Contact *create_contact(String *name, String *email, int age);
void print_contact(const Contact* contact);
void destroy_contact(Contact* contact);
void print_all_contacts(Contact** contacts, int count);

#endif //CONTACT_H
