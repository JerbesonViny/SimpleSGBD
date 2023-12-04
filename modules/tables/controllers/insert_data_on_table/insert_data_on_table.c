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

  int keep_receiving_table_names = 1;
  while (keep_receiving_table_names)
  {
    printf("Informe o nome da tabela: ");
    scanf("%s", table_name);
    int founded_table = check_table_existance(table_name);

    if (!founded_table)
    {
      printf("Tabela nao encontrada! Tente novamente!\n");
    }
    else
    {
      keep_receiving_table_names = 0;
    }
  }

  char *structure_path = create_file_path(table_name, TABLE_STRUCTURE_PATH);
  FILE *file = read_file(structure_path);

  while (fscanf(file, "%s %s", column, column_type) != EOF)
  {
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

  insert_data_on_table(quantity_of_values, values, table_name);
  fclose(file);

  for (int index = 0; index < quantity_of_values; index++)
  {
    free(values[index]);
  }
}