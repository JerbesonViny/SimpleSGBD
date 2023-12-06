#include <stdio.h>
#include <string.h>
#include "../../../../constants.h"
#include "check_table_existance.h"

int check_table_existance(char table_name[50])
{
  FILE *file = fopen(TABLE_NAMES_FILE_PATH, "r");
  char line[100];
  int table_exists = 0;

  while (fscanf(file, "%s", line) != EOF)
  {
    if (strcmp(line, table_name) == 0)
    {
      table_exists = 1;
      break;
    }
  }

  fclose(file);

  return table_exists;
}