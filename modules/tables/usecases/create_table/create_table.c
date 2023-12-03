#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../../../constants.h"
#include "../../services/display_primitive_types/display_primitive_types.h"
#include "../../services/check_table_existance/check_table_existance.h"
#include "../../controllers/create_table/create_table.h"
#include "../../../../helpers/helpers.h"

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