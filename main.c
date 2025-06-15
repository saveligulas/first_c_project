#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"
#include "string.h"

int main() {
    // String *iva_name = string_create_w_cap(3);
    // string_append_chars_explicit(iva_name, "iva", 3);
    // String *iva_email = string_create_w_cap(100);
    // string_append_chars_explicit(iva_email, "iva.gulas@gmail.com", 19);
    //
    // String *emma_name = string_create_w_cap(4);
    // string_append_chars_explicit(emma_name, "emma", 4);
    // String *emma_email = string_create_w_cap(100);
    // string_append_chars_explicit(emma_email, "emma.gulas@gmail.com", 20);
    //
    // String *bob_name = string_create_w_cap(3);
    // string_append_chars_explicit(bob_name, "bob", 3);
    // String *bob_email = string_create_w_cap(100);
    // string_append_chars_explicit(bob_email, "bob.gulas@gmail.com", 19);
    //
    // Contact *iva = create_contact(iva_name, iva_email, 11);
    // Contact *emma = create_contact(emma_name, emma_email, 12);
    // Contact *bob = create_contact(bob_name, bob_email, 13);
    //
    // Contact **my_contacts = malloc(3 * sizeof(Contact*));
    // my_contacts[0] = iva;
    // my_contacts[1] = emma;
    // my_contacts[2] = bob;
    //
    // print_all_contacts(my_contacts, 3);

    String *str = string_create();
    for (int i = 0; i < 10; i++) {
        string_append_chars(str, "abcdefghajksdfjklasdfjkljlkasdfjklaskjldfjklasdfjklajklsdfjklaskldfjklasdöfjk aösdfj aösldkjfaö slkdjföa lskdjfö alsdjkf öaklsdjf öalskdjf öaskldfj öaslkdfj ölaskdjf ölaskdfj öaslkdf jöalsdkf ");
        string_print(str);
        printf("Capacity: %d - Length: %d\n", str->capacity, str->length);
    }

    string_destroy(str);

    return 0;
}
