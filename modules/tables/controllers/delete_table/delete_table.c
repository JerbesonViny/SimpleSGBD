#include <stdio.h>
#include <stdlib.h>

#include "../../usecases/delete_table/delete_table.h"
#include "../../services/check_table_existance/check_table_existance.h"
#include "../../../../helpers/helpers.h"
#include "../../../../constants.h"
#include "delete_table.h"

void display_table_removal_status(int status)
{
  if (status)
    printf("Tabela removida com sucesso!\n");
  else
    printf("Erro ao remover tabela.\n");
}

void process_delete_table()
{
  char table_name[50];
  int can_delete_table = handle_table_name_input(table_name);

  if (can_delete_table)
  {
    int table_is_deleted = delete_table(table_name);

    system("clear");
    display_table_removal_status(table_is_deleted);
  }
}