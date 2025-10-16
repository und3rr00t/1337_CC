DONE = Done
FUNC = $(filter-out main.c, $(wildcard *.c))
all:
	@cc -Wall -Wextra -Werror *.c
	@if ./a.out; then \
		echo "succed"\
	else \
		echo "Failed"; \
	fi
