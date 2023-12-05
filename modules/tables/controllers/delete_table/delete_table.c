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
  int can_delete_table = 1;

  // TODO: Criar um helper que tenha essa logica e utilizar ele nos demais locais em que esse trecho aparece
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
        can_delete_table = 0;
      }
    }
    else
    {
      keep_receiving_table_names = 0;
    }
  }

  if (can_delete_table)
  {
    int table_are_deleted = delete_table(table_name);

    system("clear");
    display_table_removal_status(table_are_deleted);
  }
}