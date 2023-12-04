#ifndef HELPERS_H
#define HELPERS_H

int get_length_of_concatenated_text(char *first_text, char *second_text);
char *create_file_path(char *filename, char *extra_path);
void display_boolean_options();
FILE *read_file(char *file_path);

#endif