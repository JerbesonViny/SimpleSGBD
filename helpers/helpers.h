#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>

int get_length_of_concatenated_text(char *first_text, char *second_text);
char *create_file_path(char *filename, char *extra_path);
void display_boolean_options();
FILE *read_file(char *file_path);
int *search_text_in_file(char *file_path, char *text, int *length_of_indexes_array);
int includes_in_int_array(int integers_quantity, int *integers, int integer);
int delete_file(char *file_path);
int rename_file(char *file_path, char *file_name);
int handle_table_name_input(char *table_name);
void update_identifier(char table_name[50], int identifier);
int *search_identifier_in_data_file(char *file_path, char *text, int *length_of_indexes_array);

#endif