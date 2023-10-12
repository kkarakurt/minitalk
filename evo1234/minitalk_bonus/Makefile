NAME = all
$(NAME): server_bonus client_bonus
server_bonus: server_bonus.c utils_bonus.c
	@gcc -Wall -Wextra -Werror server_bonus.c utils_bonus.c -o server_bonus
	@echo Server_bonus compiled.
client_bonus: client_bonus.c utils_bonus.c
	@gcc -Wall -Wextra -Werror client_bonus.c utils_bonus.c -o client_bonus
	@echo Client_bonus compiled.
clean:
	@rm -rf server_bonus client_bonus
	@echo Everything deleted.
fclean: clean
re:
	@rm -rf server_bonus client_bonus
	@gcc -Wall -Wextra -Werror server_bonus.c utils_bonus.c -o server_bonus
	@echo Server_bonus recompiled.
	@gcc -Wall -Wextra -Werror client_bonus.c utils_bonus.c -o client_bonus
	@echo Client_bonus recompiled.
n:
	@norminette
r:
	@./server_bonus
.PHONY: n all clean fclean re r
