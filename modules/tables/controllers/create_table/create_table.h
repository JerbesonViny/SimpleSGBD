#ifndef CREATE_TABLE_CONTROLLER_H
#define CREATE_TABLE_CONTROLLER_H

typedef struct
{
  char name[50];
  char **columns;
  int columns_quantity;
} Table;

void process_create_table();

#endif