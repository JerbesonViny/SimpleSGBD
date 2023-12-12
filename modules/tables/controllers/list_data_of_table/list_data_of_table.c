#include <stdio.h>
#include "../../usecases/list_data_of_table/list_data_of_table.h"
#include "../../services/check_table_existance/check_table_existance.h"
#include "../../../../helpers/helpers.h"
#include "list_data_of_table.h"

void process_list_data_of_table()
{
  char table_name[50];

  int can_display_data_of_tables = handle_table_name_input(table_name);

  if (can_display_data_of_tables)
    list_data_of_table(table_name);
}