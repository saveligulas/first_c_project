cmake_minimum_required(VERSION 3.31)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        contact.c
        contact.h
        stringlib/include/stringlib.h
        stringlib/src/string_lifecycle.c
        stringlib/internal/string_internal.h
        stringlib/internal/string_internal.c
        stringlib/src/string_info.c
        stringlib/src/string_manipulation.c)
