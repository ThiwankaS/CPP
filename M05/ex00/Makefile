#
# Makefile for bureaucrat.
#

# Name of the program
NAME    = bureaucrat

# Compiler name
CMD     = c++

# Additional warings and errors
WARN	= -Wall -Wextra -Werror -Wshadow

# Language standrad version
STD		= -std=c++20

# Optimization flags for a release build.
CFLAGS  = $(WARN) $(STD) -O2

# Debug flags with sanitizers for debug build for OBJS.
DFLAGS  = $(WARN) $(STD) -O0 -g3 -fsanitize=address,undefined

# Source files.
SRCS    = \
	Bureaucrat.cpp\
	test.cpp\
	main.cpp

# Object files for release build.
R_OBJS    = $(SRCS:.cpp=.o)

# Object files for debug build.
D_OBJS    = $(SRCS:.cpp=.debug.o)

# Default target: build the release version.
all     : version $(NAME)

version :
	@echo "Compiler : $(CXX)"
	@$(CXX) --version | head -n 1

# Build the final executable with release flags.
$(NAME) : $(R_OBJS)
	$(CMD) $(CFLAGS) $(R_OBJS) -o $@

# Compile for relese, make sure any code chage will recompile.
%.o : %.cpp
	$(CMD) $(CFLAGS) -c $< -o $@

# Target to build the executable with debug flags.
debug   : $(NAME)_debug

# Build the final executable with debug flags
$(NAME)_debug   : $(D_OBJS)
	$(CMD) $(DFLAGS) $(D_OBJS) -o $@

# Compile for debug, make sure any code chage will recompile.
%.debug.o : %.cpp
	$(CMD) $(CFLAGS) -c $< -o $@

# Remove object files.
clean   :
	rm -rf $(R_OBJS) $(D_OBJS)

# Remove object files and the final executable.
fclean  : clean
	rm -rf $(NAME) $(NAME)_debug

# Full rebuild.
re      : fclean all

.PHONY  : all debug clean fclean re
