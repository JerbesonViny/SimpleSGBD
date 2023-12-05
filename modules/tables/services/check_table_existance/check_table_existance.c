#include <stdio.h>
#include <string.h>
#include "../../../../constants.h"
#include "check_table_existance.h"

int check_table_existance(char table_name[50])
{
  FILE *file;
  char line[100];

  file = fopen(TABLE_NAMES_FILE_PATH, "r");

  while (fscanf(file, "%s", line) != EOF)
  {
    if (strcmp(line, table_name) == 0)
    {
      return 1;
    }
  }

  return 0;
}