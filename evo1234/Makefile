NAME = all
$(NAME): server client
server: server.c utils.c
	@gcc -Wall -Wextra -Werror server.c utils.c -o server
	@echo Server compiled.
client: client.c utils.c
	@gcc -Wall -Wextra -Werror client.c utils.c -o client
	@echo Client compiled.
clean:
	@rm -rf server client
	@echo Everything deleted.
fclean: clean
re:
	@rm -rf server client
	@gcc -Wall -Wextra -Werror server.c utils.c -o server
	@echo Server recompiled.
	@gcc -Wall -Wextra -Werror client.c utils.c -o client
	@echo Client recompiled.
n:
	@norminette
r:
	@./server
.PHONY: n all clean fclean re r
