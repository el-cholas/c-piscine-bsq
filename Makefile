fclean:
	cc -c fclean.c

build:
	gcc -Wall -Werror -Wextra && gcc -Wall -Wextra -Werror *.c

free:
	cc -c free.c
