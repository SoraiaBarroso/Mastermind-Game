CC = gcc
CFLAGS += -Wall -Wextra -Werror
LINKERFLAG = -lm
SOURCES = my_mastermind.c my_mastermind.h 
OBJECTS = $(SOURCES: .c=.o)
TARGET = my_mastermind

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean fclean re

clean: 
	@rm -f *.o 

fclean: 
	@rm $(TARGET)
	$(clean) 

re: $(fclean) 
	$(MAKE)