build: create-dependence-dirs
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
	./modules/tables/controllers/list_data_of_table/list_data_of_table.c \
	./modules/tables/controllers/delete_table/delete_table.c \
	\
	./modules/tables/usecases/create_table/create_table.c \
	./modules/tables/usecases/list_tables/list_tables.c \
	./modules/tables/usecases/insert_data_on_table/insert_data_on_table.c \
	./modules/tables/usecases/list_data_of_table/list_data_of_table.c \
	./modules/tables/usecases/delete_table/delete_table.c \
	\
	-o output/main.c

create-dependence-dirs:
	if [ ! -d output ]; then mkdir output; fi \
	&& if [ ! -d tables ]; then mkdir tables; fi \
	&& if [ ! -d tables/data ]; then mkdir tables/data; fi \
	&& if [ ! -d tables/structure ]; then mkdir tables/structure; fi \
	&& if [ ! -d tables/identifier ]; then mkdir tables/identifier; fi \
	&& if [ ! -d tables/table_names.txt ]; then touch tables/table_names.txt; fi

run: 
	./output/main.c

