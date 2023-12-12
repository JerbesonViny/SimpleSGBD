#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "delete_data_of_table.h"
#include "../../services/check_table_existance/check_table_existance.h"
#include "../../services/display_primitive_types/display_primitive_types.h"
#include "../../usecases/delete_data_of_table/delete_data_of_table.h"
#include "../../../../constants.h"
#include "../../../../helpers/helpers.h"

void display_delete_message(int data_is_deleted)
{
  if (data_is_deleted)
  {
    printf("Registro apagado com sucesso!\n");
  }
  else
  {
    printf("Erro ao tentar apagar registro!\n");
  }
}

void process_delete_data_of_table()
{
  char table_name[50];

  int can_delete_data_of_table = handle_table_name_input(table_name);

  if (can_delete_data_of_table)
  {
    char identifier[50];
    int identifier_is_valid = 0;
    int keep_receiving_identifiers = 1;

    while (keep_receiving_identifiers)
    {
      printf("Informe o identificador unico do registro que deve ser apagado: ");
      scanf("%s", identifier);

      int indexes_quantity = 0;
      char *path = create_file_path(table_name, TABLE_DATA_PATH);
      int *index = search_identifier_in_data_file(path, identifier, &indexes_quantity);

      if (!indexes_quantity)
      {
        printf("Nao existe nenhum registro com esse identificador!");
        display_boolean_options();
        printf("Deseja tentar novamente? ");

        int option;
        scanf("%d", &option);

        if (!option)
        {
          keep_receiving_identifiers = 0;
          break;
        }
        else if (option != 1)
        {
          printf("Opçao invalida! Tente novamente!\n");
        }
      }
      else
      {
        identifier_is_valid = 1;
        keep_receiving_identifiers = 0;
      }
    }

    if (identifier_is_valid)
    {
      int data_is_deleted = delete_data_of_table(table_name, identifier);

      display_delete_message(data_is_deleted);
    }
  }
}