#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "helpers.h"
#include "../constants.h"
#include "../modules/tables/services/table_service.h"

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

void display_boolean_options()
{
  printf("0 - Não\n1 - Sim\n");
}

FILE *read_file(char *file_path)
{
  return fopen(file_path, "r");
}

int *search_text_in_file(char *file_path, char *text, int *length_of_indexes_array)
{
  FILE *file = read_file(file_path);

  char line[1024];
  int founded_lines_quantity = 0;
  int *indexes_of_lines = malloc(founded_lines_quantity * sizeof(int));

  int line_index = 0;
  while (fscanf(file, "%s", line) != EOF)
  {
    if (strcmp(line, text) == 0)
    {
      founded_lines_quantity++;
      indexes_of_lines = (int *)realloc(indexes_of_lines, founded_lines_quantity * sizeof(int));

      indexes_of_lines[founded_lines_quantity - 1] = line_index;
    }

    line_index++;
  }

  *length_of_indexes_array = founded_lines_quantity;

  return indexes_of_lines;
}

int *search_identifier_in_data_file(char *file_path, char *text, int *length_of_indexes_array)
{
  FILE *file = read_file(file_path);

  char line[1024];
  int founded_lines_quantity = 0;
  int *indexes_of_lines = malloc(founded_lines_quantity * sizeof(int));

  int line_index = 0;
  while (fscanf(file, "%s", line) != EOF)
  {
    char *identifier = strtok(line, ";");

    if (strcmp(identifier, text) == 0)
    {
      founded_lines_quantity++;
      indexes_of_lines = (int *)realloc(indexes_of_lines, founded_lines_quantity * sizeof(int));

      indexes_of_lines[founded_lines_quantity - 1] = line_index;
    }

    line_index++;
  }

  *length_of_indexes_array = founded_lines_quantity;

  return indexes_of_lines;
}

int includes_in_int_array(int integers_quantity, int *integers, int integer)
{
  for (int index = 0; index < integers_quantity; index++)
  {
    if (integers[index] == integer)
      return 1;
  }

  return 0;
}

int delete_file(char *file_path)
{
  if (remove(file_path) == 0)
    return 1;

  return 0;
}

int rename_file(char *file_path, char *file_name)
{
  if (rename(file_path, file_name) == 0)
    return 1;

  return 0;
}

int handle_table_name_input(char *table_name)
{
  int keep_receiving_table_names = 1;

  while (keep_receiving_table_names)
  {
    printf("Informe o nome da tabela: ");
    scanf("%s", table_name);
    int founded_table = check_table_existance(table_name);

    if (!founded_table)
    {
      printf("Tabela nao encontrada!\n");
      display_boolean_options();

      printf("Deseja tentar novamente? ");

      int option;
      scanf("%d", &option);

      if (option == 0)
      {
        keep_receiving_table_names = 0;
      }
    }
    else
    {
      keep_receiving_table_names = 0;
    }
  }
}

void update_identifier(char table_name[50], int identifier)
{
  char *file_path = create_file_path(table_name, TABLE_IDENTIFIER_PATH);
  int identifier_file_is_deleted = delete_file(file_path);
  FILE *file = fopen(file_path, "a+");

  char identifier_string[50];
  sprintf(identifier_string, "%d", identifier);
  fprintf(file, "%s\n", identifier_string);

  fclose(file);
}