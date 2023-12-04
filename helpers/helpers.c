#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "helpers.h"

int get_length_of_concatenated_text(char *first_text, char *second_text)
{
  int first_string_length = strlen(first_text);
  int second_string_length = strlen(second_text);

  return (first_string_length + second_string_length + 1) * sizeof(char);
}

char *create_file_path(char *filename, char *extra_path)
{
  char *path;

  int path_length = get_length_of_concatenated_text(filename, extra_path);
  path = (char *)malloc(path_length);

  sprintf(path, "%s/%s", extra_path, filename);

  return path;
}

FILE *read_file(char *file_path)
{
  return fopen(file_path, "r");
}