#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "insert_data_on_table.h"
#include "../../services/check_table_existance/check_table_existance.h"
#include "../../../../helpers/helpers.h"
#include "../../../../constants.h"

void insert_data_on_table(int quantity_of_values, char **values, char table_name[50])
{
  char *data_path = create_file_path(table_name, TABLE_DATA_PATH);
  FILE *file = fopen(data_path, "a");

  for (int index = 0; index < quantity_of_values; index++)
  {
    if (index != quantity_of_values - 1)
    {
      fprintf(file, "%s;", values[index]);
    }
    else
    {
      fprintf(file, "%s\n", values[index]);
    }
  }

  fclose(file);
  free(data_path);
}