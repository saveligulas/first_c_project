cmake_minimum_required(VERSION 3.31)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        contact.c
        contact.h
        stryx/include/stryx.h
        stryx/src/string_lifecycle.c
        stryx/internal/_string_internal.h
        stryx/internal/string_internal.c
        stryx/src/string_info.c
        stryx/src/string_manipulation.c
        stryx/src/string_extraction.c)
