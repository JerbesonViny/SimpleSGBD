#include <stdio.h>
#include "../../../../constants.h"
#include "list_tables.h"

FILE *load_tables()
{
  return fopen(TABLE_PATH, "r");
}

void list_tables()
{
  FILE *file = load_tables();
  char line[100];
  int columns_quantity = 1;

  printf("--- Tabelas ---\n");
  while (fscanf(file, "%s", line) != EOF)
  {
    printf("%d - %s\n", columns_quantity, line);
    columns_quantity++;
  }
}