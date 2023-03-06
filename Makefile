NAME			=	containers

SRC_DIR		=	./src/
OBJ_DIR		=	obj/

TEMPS_DIR	=	./includes/templates/
IMPS_DIR	=	./includes/implementations/
HDRS_DIR	=	./includes/headers/

MAIN_INC	= -I $(HDRS_DIR) -I $(TEMPS_DIR) -I $(IMPS_DIR)

TEMPS		=	$(shell find $(TEMPS_DIR) -type f -name "*.tpp")
IMPS		=	$(shell find $(IMPS_DIR) -type f -name "*.ipp")
HDRS		= 	$(shell find $(HDRS_DIR) -type f -name "*.hpp")

SRC			=	main.cpp   \
				iteratorsTest.cpp \
				riteratorsTest.cpp \

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp $(HDRS) $(TEMPS) $(IMPS) Makefile
		@mkdir -p $(OBJ_DIR)
		$(CC) ${CFLAGS}  $(MAIN_INC) -o $@ -c $<

$(NAME)		:	$(OBJ) $(HDRS) $(TEMPS) $(IMPS)
		$(CC) $(CFLAGS) $(OBJ) $(MAIN_INC) -o $(NAME)
					
all			:	$(NAME)

clean		:
		@rm -rf $(OBJ_DIR)

fclean		:	clean
		@rm -rf $(NAME)

re			:	fclean	all

.PHONY		:	all clean fclean re