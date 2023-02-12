CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c
SRC_UTILS = minitalk_utils.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)


$(CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS) minitalk.h
	@$(CC) $(OBJ_CLIENT) $(OBJ_UTILS) $(CFLAGS) -o $(CLIENT)
	@echo "$(GREEN)CLIENT COMPILED SUCCESSFULLY !"
$(SERVER): $(OBJ_SERVER) $(OBJ_UTILS) minitalk.h
	@$(CC) $(OBJ_SERVER) $(OBJ_UTILS) $(CFLAGS) -o $(SERVER)
	@echo "$(GREEN)SERVER COMPILED SUCCESSFULLY !"

$(CLIENT_BONUS):  $(OBJ_CLIENT_BONUS) $(OBJ_UTILS) minitalk.h
	@$(CC) $(OBJ_CLIENT_BONUS) $(OBJ_UTILS) $(CFLAGS) -o $(CLIENT_BONUS)
	@echo "$(GREEN)CLIENT BONUS COMPILED SUCCESSFULLY !"
$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(OBJ_UTILS) minitalk.h
	@$(CC) $(OBJ_SERVER_BONUS) $(OBJ_UTILS) $(CFLAGS) -o $(SERVER_BONUS)
	@echo "$(GREEN)SERVER BONUS COMPILED SUCCESSFULLY !"

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

%.o: %.c 
	@$(CC) -c $(CFLAGS) $?
		
clean:
	@rm -f $(OBJ_CLIENT)
	@rm -f $(OBJ_SERVER)
	@rm -f server_bonus.o
	@rm -f client_bonus.o
	@rm -f $(OBJ_UTILS)
	@echo "$(RED)OBJECTS FILES REMOVED !"
fclean: clean
	@rm -f $(CLIENT)
	@rm -f $(SERVER)
	@rm -f $(CLIENT_BONUS)
	@rm -f $(SERVER_BONUS)
	@echo "$(RED)EXCUTABLES REMOVED !"
re: fclean all


	