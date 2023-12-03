#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../../../constants.h"
#include "../../services/display_primitive_types/display_primitive_types.h"
#include "../../services/check_table_existance/check_table_existance.h"
#include "../../controllers/create_table/create_table.h"

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

void create_table_on_table_names_file(char table_name[50])
{
  FILE *file;

  if (access(TABLE_PATH, F_OK) != -1)
  {
    file = fopen(TABLE_PATH, "a");
  }
  else
  {
    file = fopen(TABLE_PATH, "a+");
  }

  fprintf(file, "%s\n", table_name);

  fclose(file);
}

void create_table_structure_file(Table *table)
{
  FILE *file;
  char *path = create_file_path(table->name, TABLE_STRUCTURE_PATH);

  if (access(path, F_OK) != -1)
  {
    file = fopen(path, "a");
  }
  else
  {
    file = fopen(path, "a+");
  }

  fprintf(file, "%d\n", table->columns_quantity);

  for (int column_index = 0; column_index < table->columns_quantity; column_index++)
  {

    fprintf(file, "%s\n", table->columns[column_index]);
  }

  fclose(file);
}

void create_table_data_file(Table *table)
{
  FILE *file;
  char *path = create_file_path(table->name, TABLE_DATA_PATH);

  if (access(path, F_OK) != -1)
  {
    file = fopen(path, "a");
  }
  else
  {
    file = fopen(path, "a+");
  }

  int last_index_of_columns = table->columns_quantity - 1;
  for (int column_index = 0; column_index < table->columns_quantity; column_index++)
  {
    if (column_index != last_index_of_columns)
    {
      fprintf(file, "%s;", strtok(table->columns[column_index], " "));
    }
    else
    {
      fprintf(file, "%s\n", strtok(table->columns[column_index], " "));
    }
  }

  fclose(file);
}

void create_table_files(Table *table)
{
}

void create_table(Table *table)
{
  create_table_on_table_names_file(table->name);
  create_table_structure_file(table);
  create_table_data_file(table);
  printf("Tabela criada com sucesso!\n");
}