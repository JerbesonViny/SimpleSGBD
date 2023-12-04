#include <stdio.h>
#include "../../usecases/list_data_of_table/list_data_of_table.h"
#include "../../services/check_table_existance/check_table_existance.h"
#include "../../../../helpers/helpers.h"
#include "list_data_of_table.h"

void process_list_data_of_table()
{
  char table_name[50];
  int display_data_of_table = 1;

  int keep_receiving_table_names = 1;
  while (keep_receiving_table_names)
  {
    printf("Informe o nome da tabela: ");
    scanf("%s", table_name);
    int founded_table = check_table_existance(table_name);

    if (!founded_table)
    {
      printf("Tabela nao encontrada!\n");
      display_boolean_options();

      printf("Deseja tentar novamente? ");

      int option;
      scanf("%d", &option);

      if (option == 0)
      {
        keep_receiving_table_names = 0;
        display_data_of_table = 0;
      }
    }
    else
    {
      keep_receiving_table_names = 0;
    }
  }

  if (display_data_of_table)
    list_data_of_table(table_name);
}