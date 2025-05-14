#-----------------------COMPILATION------------------------------------------------------
# Compiler and Flags
CC						:= cc
CFLAGS				 	 = -Wall -Wextra -Werror $(INCLUDES) -g
LDFLAGS					:= 
INCLUDES				 = $(addprefix -I,$(SRC_DIRS)) $(addprefix -I,$(LIB_DIRS))

#-----------------------BINARIES---------------------------------------------------------
# Output Files
NAME					:= cub3D
LIBRARY_FOR_TESTS		:= libcub3D.a

#-----------------------ROOT FOLDERS----------------------------------------------------------
# Directories
SRC_DIR					:= src
OBJ_DIR					:= obj
LIB_DIR 				:= libraries

#-----------------------SOURCE FOLDERS----------------------------------------------------------

# Source directories (src/)
BUILDERS_DIR			:= $(SRC_DIR)/builders
HELPERS_DIR				:= $(SRC_DIR)/helpers
LOGIC_DIR				:= $(SRC_DIR)/logic
MODEL_DIR				:= $(SRC_DIR)/model
SHARED_DIR				:= $(SRC_DIR)/shared

# List of all source directories
SRC_DIRS				:= $(SRC_DIR) \
							$(BUILDERS_DIR) \
							$(HELPERS_DIR) \
							$(LOGIC_DIR) \
							$(MODEL_DIR) \
							$(SHARED_DIR)

#-----------------------SOURCE FILES------------------------------------------------------------
# Sources
C_FILES 				:= $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
HEADERS 				:= $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.h))

# Objects
OBJ     				:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(C_FILES)))

#-----------------------LIBRARY FOLDERS----------------------------------------------------------
# Library directories (libraries/)
STRING_LIB_DIR			:= $(LIB_DIR)/ft_string
LIST_LIB_DIR			:= $(LIB_DIR)/list
GNL_LIB_DIR				:= $(LIB_DIR)/get_next_line
CONVERTER_LIB_DIR		:= $(LIB_DIR)/converter
FILE_LIB_DIR			:= $(LIB_DIR)/file

# List of all library directories
LIB_DIRS				:= $(STRING_LIB_DIR) \
							$(LIST_LIB_DIR) \
							$(GNL_LIB_DIR) \
							$(CONVERTER_LIB_DIR) \
							$(FILE_LIB_DIR)

#-----------------------LIBRARIES--------------------------------------------------------
# Libraries
STRING_LIB				:= $(STRING_LIB_DIR)/ft_string.a
LIST_LIB				:= $(LIST_LIB_DIR)/list.a
GNL_LIB					:= $(GNL_LIB_DIR)/get_next_line.a
CONVERTER_LIB			:= $(CONVERTER_LIB_DIR)/converter.a
FILE_LIB				:= $(FILE_LIB_DIR)/file.a

# List of all libraries
LIBRARIES				:= $(STRING_LIB) \
							$(LIST_LIB) \
							$(GNL_LIB) \
							$(CONVERTER_LIB) \
							$(FILE_LIB)

#-----------------------COLORS-----------------------------------------------------------
# Colors for Output
GREEN					:= \033[0;32m
RED						:= \033[31m
RESET					:= \033[0m

#-----------------------RULES------------------------------------------------------------
vpath %.c $(SRC_DIRS)
vpath %.h $(SRC_DIRS)

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

# Compile Object Files
$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile libraries
%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null

$(LIBRARY_FOR_TESTS): $(OBJ) $(LIBRARIES)
	@for lib in $(LIBRARIES); do \
		ar x $$lib ; \
		ar src $@ *.o ; \
		rm *.o ; \
	done
	@ar src $@ $(OBJ)
	@ar d $@ main.o

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed object files$(RESET)"
	@for lib in $(LIB_DIR)/*; do \
		if [ -f $$lib/Makefile ]; then \
			$(MAKE) -C $$lib clean > /dev/null; \
		fi \
	done

# Clean up All Generated Files
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"
	@for lib in $(LIB_DIR)/*; do \
		if [ -f $$lib/Makefile ]; then \
			$(MAKE) -C $$lib fclean > /dev/null; \
		fi \
	done

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re

print:
	@echo $(notdir $(C_FILES)) | tr ' ' '\n' > c_files.txt
	@echo $(notdir $(HEADERS)) | tr ' ' '\n' > headers.txt