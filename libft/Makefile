DONE = Done
FUNC = $(filter-out main.c, $(wildcard *.c))
all:
	@cc -Wall -Wextra -Werror *.c
	@if ./a.out; then \
		mv $(FUNC) $(DONE)/; \
	else \
		echo "Failed"; \
	fi
	rm -rf a.out
