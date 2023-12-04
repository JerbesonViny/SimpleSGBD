#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list_data_of_table.h"
#include "../../../../helpers/helpers.h"
#include "../../../../constants.h"

void list_data_of_table(char table_name[50])
{
  char *data_path = create_file_path(table_name, TABLE_DATA_PATH);
  FILE *file = read_file(data_path);

  char line[1000];
  int columns_quantity = 1;

  printf("--- %s ---\n", table_name);
  while (fscanf(file, "%s", line) != EOF)
  {
    char *column = strtok(line, ";");

    while (column != NULL)
    {
      printf("| %-25s |", column);

      column = strtok(NULL, ";");
    }

    printf("\n");
  }
};