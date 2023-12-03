#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "modules/tables/services/table_service.h"
#include "modules/tables/controllers/create_table/create_table.h"

void process_option(int option)
{
	if (option == 1)
	{
		process_create_table();
	}
}

int main(void)
{
	int option = -1;
	display_features();

	while (option != 0)
	{
		scanf("%d", &option);
		process_option(option);
		getchar();
	}

	return 0;
}
