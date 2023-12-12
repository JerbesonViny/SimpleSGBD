#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "insert_data_on_table.h"
#include "../../services/check_table_existance/check_table_existance.h"
#include "../../usecases/insert_data_on_table/insert_data_on_table.h"
#include "../../../../helpers/helpers.h"
#include "../../../../constants.h"

void process_insert_data_on_table()
{
  char table_name[50];
  char column[50];
  char column_type[20];
  char *values[500];
  int quantity_of_values = 0;

  int can_insert_data = handle_table_name_input(table_name);

  if (!can_insert_data)
    return;

  char *structure_file_path = create_file_path(table_name, TABLE_STRUCTURE_PATH);
  FILE *structure_file = read_file(structure_file_path);

  while (fscanf(structure_file, "%s %s", column, column_type) != EOF)
  {
    if (strcmp(column, "id") == 0)
      continue;

    printf("Insira um valor para o campo %s (%s): ", column, column_type);

    if (strcmp(column_type, "String") == 0)
    {
      char value[500];

      scanf("%s", value);

      quantity_of_values++;
      values[quantity_of_values - 1] = malloc(quantity_of_values * sizeof(char *));
      strcpy(values[quantity_of_values - 1], value);
    }
    else if (strcmp(column_type, "Int") == 0)
    {
      int value;
      char value_string[500];

      scanf("%d", &value);
      sprintf(value_string, "%d", value);

      quantity_of_values++;
      values[quantity_of_values - 1] = malloc(quantity_of_values * sizeof(char *));
      strcpy(values[quantity_of_values - 1], value_string);
    }
    else if (strcmp(column_type, "Float") == 0)
    {
      float value;
      char value_string[500];

      scanf("%f", &value);
      sprintf(value_string, "%f", value);

      quantity_of_values++;
      values[quantity_of_values - 1] = malloc(quantity_of_values * sizeof(char *));
      strcpy(values[quantity_of_values - 1], value_string);
    }
  }

  char *identifier_file_path = create_file_path(table_name, TABLE_IDENTIFIER_PATH);
  FILE *identifier_file = read_file(identifier_file_path);

  char last_identifier_string[50];
  fscanf(identifier_file, "%s", last_identifier_string);
  int identifier = atoi(last_identifier_string) + 1;

  insert_data_on_table(quantity_of_values, values, table_name, identifier);
  update_identifier(table_name, identifier);

  fclose(structure_file);
  fclose(identifier_file);

  free(structure_file_path);
  free(identifier_file_path);
  for (int index = 0; index < quantity_of_values; index++)
  {
    free(values[index]);
  }
}