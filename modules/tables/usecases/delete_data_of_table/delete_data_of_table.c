#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "delete_data_of_table.h"
#include "../../../../helpers/helpers.h"
#include "../../../../constants.h"

int delete_data_of_table(char table_name[50], char *identifier)
{
  int indexes_quantity = 0;
  char *path = create_file_path(table_name, TABLE_DATA_PATH);
  int *indexes = search_identifier_in_data_file(path, identifier, &indexes_quantity);

  char *temp_data_table_file_path = create_file_path("temp_data_table", TABLE_DATA_PATH);
  FILE *temp_file = fopen(temp_data_table_file_path, "w");
  FILE *data_table_file = fopen(path, "r");

  char line[1024];
  int index = 0;

  while (fscanf(data_table_file, "%s", line) != EOF)
  {
    if (!includes_in_int_array(indexes_quantity, indexes, index))
      fprintf(temp_file, "%s\n", line);

    index++;
  }

  fclose(temp_file);
  fclose(data_table_file);

  int original_file_is_deleted = delete_file(path);
  int temp_file_is_renamed = rename_file(temp_data_table_file_path, path);

  free(indexes);
  free(temp_data_table_file_path);

  if (original_file_is_deleted && temp_file_is_renamed)
    return 1;

  return 0;
}