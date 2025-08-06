#
# Makefile for phonebook.
#

NAME    = phonebook
CMD     = c++

# Optimization flags for a release build.
CFLAGS  = -Wall -Wextra -Werror -std=c++20 -O3

# Debug flags with sanitizers for a debug build.
DFLAGS  = -Wall -Wextra -Werror -g -fsanitize=address,undefined

# Source and object files.
SRCS    = \
		Contact.cpp\
		PhoneBook.cpp\
		validate.cpp\
		main.cpp
OBJS    = $(SRCS:.cpp=.o)

# Default target: build the release version.
all     : $(NAME)

# Target to build the final executable with release flags.
$(NAME) : $(OBJS)
	$(CMD) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule for creating object files from source files.
# This ensures that only changed files are recompiled.
%.o : %.cpp
	$(CMD) $(CFLAGS) -c $< -o $@

# Target to build the executable with debug flags.
debug   : $(OBJS)
	$(CMD) $(DFLAGS) $(OBJS) -o $(NAME)

# Remove object files.
clean   :
	rm -rf $(OBJS)

# Remove object files and the final executable.
fclean  : clean
	rm -rf $(NAME)

# Full rebuild.
re      : fclean all

.PHONY  : all debug clean fclean re
