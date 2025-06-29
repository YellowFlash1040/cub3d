#-----------------------COMPILATION------------------------------------------------------
# Compiler and Flags
CC						:= cc
CFLAGS				 	 = -Wall -Wextra -Werror $(INCLUDES) -g
LDFLAGS					:= -ldl -lglfw -pthread -lm
INCLUDES				 = $(addprefix -I,$(SRC_DIRS)) \
							$(addprefix -I,$(LIB_DIRS)) \
							-I$(MLX_REPO_DIR)/include

#-----------------------BINARIES---------------------------------------------------------
# Output Files
NAME					:= cub3d
LIBRARY_FOR_TESTS		:= libcub3d.a

#-----------------------ROOT FOLDERS----------------------------------------------------------
# Directories
SRC_DIR					:= src
OBJ_DIR					:= obj
LIB_DIR 				:= libraries

SRC_DIRS				 = $(patsubst %/, %, $(sort $(dir $(HEADERS))))

#-----------------------ADDITIONAL SETUP------------------------------------------
COMPILE_MSG_SHOWN		:=

ASSETS_DIR				:= assets
TEXTURES_DIR			:= $(ASSETS_DIR)/textures
TEXTURES_ARCHIVE		:= $(ASSETS_DIR)/archives/textures.zip

#-----------------------SOURCE FILES------------------------------------------------------------
# Sources
C_FILES 				:= $(shell find $(SRC_DIR) -name '*.c')
HEADERS 				:= $(shell find $(SRC_DIR) -name '*.h')

# Objects
OBJ     				:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_FILES))

#-----------------------LIBRARY FOLDERS----------------------------------------------------------

#MLX42
MLX_REPO_DIR			:= $(LIB_DIR)/mlx42

# Library directories (libraries/)
MLX_LIB_DIR				:= $(MLX_REPO_DIR)/build
STRING_LIB_DIR			:= $(LIB_DIR)/ft_string
LIST_LIB_DIR			:= $(LIB_DIR)/list
GNL_LIB_DIR				:= $(LIB_DIR)/get_next_line
CONVERTER_LIB_DIR		:= $(LIB_DIR)/converter
FILE_LIB_DIR			:= $(LIB_DIR)/file
MEMORY_LIB_DIR			:= $(LIB_DIR)/ft_memory
STRING_ARRAY_LIB_DIR	:= $(LIB_DIR)/string_array

# List of all library directories
LIB_DIRS				:= $(MLX_LIB_DIR) \
							$(STRING_LIB_DIR) \
							$(LIST_LIB_DIR) \
							$(GNL_LIB_DIR) \
							$(CONVERTER_LIB_DIR) \
							$(FILE_LIB_DIR) \
							$(MEMORY_LIB_DIR) \
							$(STRING_ARRAY_LIB_DIR)

#-----------------------LIBRARIES--------------------------------------------------------
# Libraries
MLX_LIB     			:= $(MLX_LIB_DIR)/libmlx42.a
STRING_LIB				:= $(STRING_LIB_DIR)/ft_string.a
LIST_LIB				:= $(LIST_LIB_DIR)/list.a
GNL_LIB					:= $(GNL_LIB_DIR)/get_next_line.a
CONVERTER_LIB			:= $(CONVERTER_LIB_DIR)/converter.a
FILE_LIB				:= $(FILE_LIB_DIR)/file.a
MEMORY_LIB				:= $(MEMORY_LIB_DIR)/ft_memory.a
STRING_ARRAY_LIB		:= $(STRING_ARRAY_LIB_DIR)/string_array.a

# List of all libraries
LIBRARIES				:= $(MLX_LIB) \
							$(STRING_LIB) \
							$(LIST_LIB) \
							$(GNL_LIB) \
							$(CONVERTER_LIB) \
							$(FILE_LIB) \
							$(MEMORY_LIB) \
							$(STRING_ARRAY_LIB)

#-----------------------COLORS-----------------------------------------------------------
# Colors for Output
GREEN					:= \033[0;32m
RED						:= \033[0;31m
BLUE					:= \033[0;34m
YELLOW					:= \033[0;33m
RESET					:= \033[0m

#-----------------------RULES------------------------------------------------------------

# Default Target
all: $(TEXTURES_DIR) $(MLX_LIB) $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

# Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile
	$(if $(COMPILE_MSG_SHOWN),,$(eval COMPILE_MSG_SHOWN := 1) \
	@echo "$(YELLOW)>> Compiling object files...$(RESET)")
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile custom libraries
%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null

# Compile mlx42 library
$(MLX_LIB):
	@if [ ! -d "$(MLX_REPO_DIR)" ] || [ -z "$$(ls -A $(MLX_REPO_DIR))" ]; then \
		echo "$(YELLOW)>> Initializing MLX42 submodule...$(RESET)"; \
		git submodule update --init --recursive $(MLX_REPO_DIR) > /dev/null 2>&1; \
	fi
	@echo "$(YELLOW)>> Building MLX42...$(RESET)"
	@cmake -S $(MLX_REPO_DIR) -Wno-dev -B $(MLX_REPO_DIR)/build > /dev/null
	@cmake --build $(MLX_REPO_DIR)/build > /dev/null

# Prepare textures
$(TEXTURES_DIR):
	@if [ ! -d "$(TEXTURES_DIR)" ] || [ -z "$$(ls -A $(TEXTURES_DIR))" ]; then \
		echo "$(YELLOW)>> Extracting textures...$(RESET)"; \
		unzip -q $(TEXTURES_ARCHIVE) -d $(ASSETS_DIR); \
	fi

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
	@rm -rf $(TEXTURES_DIR)
	@echo "$(RED)Removed textures$(RESET)"
	@for lib in $(LIB_DIR)/*; do \
		if [ -f $$lib/Makefile ]; then \
			$(MAKE) -C $$lib fclean > /dev/null; \
		fi \
	done

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re

# Print all of the source (.c, .h) files list, to help prepare makefile for an eval
print:
	@echo $(C_FILES) | tr ' ' '\n' > c_files.txt
	@echo $(HEADERS) | tr ' ' '\n' > headers.txt
