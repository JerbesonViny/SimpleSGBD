build: create-output-dir 
	gcc ./main.c ./constants.h \
	\
	./helpers/helpers.c \
	\
	./modules/tables/services/display_features/display_features.c \
	./modules/tables/services/check_table_existance/check_table_existance.c \
	./modules/tables/services/display_primitive_types/display_primitive_types.c \
	./modules/tables/services/table_service.h \
	\
	./modules/tables/controllers/create_table/create_table.c \
	./modules/tables/controllers/list_tables/list_tables.c \
	./modules/tables/controllers/insert_data_on_table/insert_data_on_table.c \
	\
	./modules/tables/usecases/create_table/create_table.c \
	./modules/tables/usecases/list_tables/list_tables.c \
	./modules/tables/usecases/insert_data_on_table/insert_data_on_table.c \
	\
	-o output/main.c

create-output-dir:
	if [ ! -d output ]; then mkdir output; fi

run: 
	./output/main.c

