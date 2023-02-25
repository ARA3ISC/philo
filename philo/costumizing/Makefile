CC = gcc

all: compiling

compiling: compiling.c
	@$(CC) $(CFLAGS) $< -o $@
	@./compiling
	@rm -f compiling

.PHONY: clean
clean: deleting.c
	@rm -f compiling

.PHONY: run
run: compiling
	./compiling

