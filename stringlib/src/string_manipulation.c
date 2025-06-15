#include <stdlib.h>
#include <string.h>

#include "../include/stringlib.h"
#include "../internal/string_internal.h"

bool string_append(String* str, const char* text) {
   if (_is_invalid(str)) return false;

   _append_chars(str, text, strlen(text));
   return true;
}

bool string_append_char(String* str, char c) {
   if (_is_invalid(str)) return false;

   _append_char(str, c);
   return true;

}
void string_clear(String** str) {
   if (str != NULL && *str != NULL) {
      string_destroy(*str);
      *str = string_create_empty();
   }
}

bool string_insert(String* str, size_t pos, const char* text) {
   if (_is_invalid(str)) return false;
   if (text == NULL) return false;

   if (pos  > str->length) return false;

   if (pos == str->length) {
      return string_append(str, text);
   }

   size_t len = strlen(text);

   if (pos + strlen(text) >= str->capacity) {
      _set_string_capacity(str, _calc_new_capacity(str->capacity, len));
   }

   memmove(str->data + pos + len, str->data + pos, str->length - pos);
   memcpy(str->data + pos, text, len);
   str->length += len;
   str->data[str->length] = NULL_CHAR;
   return true;
}
