NAME			=	containers

SRC_DIR		=	./src/
OBJ_DIR		=	obj/

IMPS_DIR	=	./includes/implementations/
HDRS_DIR	=	./includes/headers/
TEST_DIR	=	./includes/tests/

HDRS_CONT	=	$(HDRS_DIR)/containers/
HDRS_ITER	=	$(HDRS_DIR)/iterators/
HDRS_UTILS	=	$(HDRS_DIR)/utils/

IMPS_CONT	=	$(IMPS_DIR)/containers/
IMPS_ITER	=	$(IMPS_DIR)/iterators/
IMPS_UTILS	=	$(IMPS_DIR)/utils/

MAIN_INC	= -I $(HDRS_DIR) -I $(HDRS_CONT) -I $(HDRS_ITER) -I $(HDRS_UTILS) -I $(IMPS_DIR) -I $(IMPS_CONT) -I $(IMPS_ITER) -I $(IMPS_UTILS) -I $(TEST_DIR)

IMPS		=	$(shell find $(IMPS_DIR) -type f -name "*.ipp")
HDRS		= 	$(shell find $(HDRS_DIR) -type f -name "*.hpp")
TESTS		=	$(shell find $(TEST_DIR) -type f -name "*.hpp")

SRC			=	main.cpp   \
				mapTest.cpp \
				vectorsTest.cpp \
				iteratorsTest.cpp \
				riteratorsTest.cpp \

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp $(HDRS) $(IMPS) $(TESTS) Makefile
		@mkdir -p $(OBJ_DIR)
		$(CC) ${CFLAGS}  $(MAIN_INC) -o $@ -c $<

$(NAME)		:	$(OBJ) $(HDRS) $(IMPS) $(TESTS)
		$(CC) $(CFLAGS) $(OBJ) $(MAIN_INC) -o $(NAME)
					
all			:	$(NAME)

clean		:
		@rm -rf $(OBJ_DIR)

fclean		:	clean
		@rm -rf $(NAME)

re			:	fclean	all

.PHONY		:	all clean fclean re