build:
	gcc ./main.c ./constants.h \
	\
	./modules/tables/services/display_features/display_features.c \
	./modules/tables/services/check_table_existance/check_table_existance.c \
	./modules/tables/services/display_primitive_types/display_primitive_types.c \
	./modules/tables/services/table_service.h \
	\
	./modules/tables/controllers/create_table/create_table.c \
	./modules/tables/controllers/list_tables/list_tables.c \
	\
	./modules/tables/usecases/create_table/create_table.c \
	./modules/tables/usecases/list_tables/list_tables.c \
	\
	-o output/main.c

run: 
	./output/main.c

