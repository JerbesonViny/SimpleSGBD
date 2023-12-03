#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "create_table.h"
#include "../../services/check_table_existance/check_table_existance.h"
#include "../../services/display_primitive_types/display_primitive_types.h"
#include "../../usecases/create_table/create_table.h"
#include "../../../../constants.h"

void set_primitive_type(int option, char *column_type)
{
  if (option == 1)
  {
    strcpy(column_type, "String");
  }
  else if (option == 2)
  {
    strcpy(column_type, "Int");
  }
  else if (option == 3)
  {
    strcpy(column_type, "Float");
  }
}

void display_boolean_options()
{
  printf("0 - Não\n1 - Sim\n");
}

void process_create_table()
{
  Table table = {};

  printf("Informe o nome da tabela: ");
  scanf("%s", table.name);
  int founded_table = check_table_existance(table.name);

  if (founded_table)
  {
    printf("Nao foi possivel criar a tabela pois ja existe uma com essa assinatura.\n");
  }
  else
  {
    int keep_receiving_input = 1;

    while (keep_receiving_input)
    {
      char column_name[50], column_type[20], line[70] = {};
      int column_type_option;

      printf("Informe o nome da coluna: ");
      scanf("%s", column_name);

      printf("Esses sao os tipos disponiveis\n");
      display_primitive_types();
      printf("Escolha um entre os tipos primitivos para a coluna criada: ");

      scanf("%d", &column_type_option);
      set_primitive_type(column_type_option, column_type);

      strcat(line, column_name);
      strcat(line, " ");
      strcat(line, column_type);

      table.columns_quantity++;
      table.columns = (char **)realloc(table.columns, table.columns_quantity * sizeof(char *));
      table.columns[table.columns_quantity - 1] = (char *)realloc(table.columns[table.columns_quantity - 1], 70 * sizeof(char));
      strcpy(table.columns[table.columns_quantity - 1], line);

      while (1)
      {
        printf("Gostaria de adicionar uma nova coluna?\n");
        display_boolean_options();
        printf("Escolha das duas opcoes possiveis: ");

        int option;
        scanf("%d", &option);

        if (!option)
        {
          keep_receiving_input = 0;
          break;
        }
        else if (option != 1)
        {
          printf("Opçao invalida! Tente novamente!\n");
        }
        else
        {
          break;
        }
      }
    }

    // chamar o caso de uso
    create_table(&table);
  }
}