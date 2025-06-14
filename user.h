//
// Created by savel on 14/06/2025.
//

#ifndef USER_H
#define USER_H
#include "string.h"

typedef struct User User;

struct User {
    String *name;
    String *password;
};



#endif //USER_H
