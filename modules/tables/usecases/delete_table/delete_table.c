#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "delete_table.h"
#include "../../../../helpers/helpers.h"
#include "../../../../constants.h"

int delete_structure_file(char table_name[50])
{
  char *structure_path = create_file_path(table_name, TABLE_STRUCTURE_PATH);
  int file_is_removed = delete_file(structure_path);

  free(structure_path);

  return file_is_removed;
}

int delete_data_file(char table_name[50])
{
  char *data_path = create_file_path(table_name, TABLE_DATA_PATH);
  int file_is_removed = delete_file(data_path);

  free(data_path);

  return file_is_removed;
}

int remove_table_of_table_names_file(char table_name[50])
{
  int indexes_quantity = 0;
  int *indexes = search_text_in_file(TABLE_NAMES_FILE_PATH, table_name, &indexes_quantity);

  char *temp_table_names_file_path = create_file_path("temp_table_names.txt", TABLE_PATH);
  FILE *temp_file = fopen(temp_table_names_file_path, "w");
  FILE *table_names_file = fopen(TABLE_NAMES_FILE_PATH, "r+");

  char line[1024];
  int index = 0;

  while (fscanf(table_names_file, "%s", line) != EOF)
  {
    if (!includes_in_int_array(indexes_quantity, indexes, index))
      fprintf(temp_file, "%s\n", line);

    index++;
  }

  fclose(temp_file);
  fclose(table_names_file);

  int temp_file_are_deleted = delete_file(TABLE_NAMES_FILE_PATH);
  int table_names_file_are_deleted = rename_file(temp_table_names_file_path, TABLE_NAMES_FILE_PATH);

  free(indexes);
  free(temp_table_names_file_path);

  if (temp_file_are_deleted && table_names_file_are_deleted)
    return 1;

  return 0;
}

int delete_table(char table_name[50])
{
  int structure_file_are_deleted = delete_structure_file(table_name);
  int data_file_are_deleted = delete_data_file(table_name);
  int table_has_removed_to_table_names_file = remove_table_of_table_names_file(table_name);

  if (structure_file_are_deleted && data_file_are_deleted && table_has_removed_to_table_names_file)
    return 1;

  return 0;
};