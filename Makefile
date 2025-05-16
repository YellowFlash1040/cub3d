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

############################################################################################
############################################################################################
############################################################################################

#-----------------------ROOT FOLDERS----------------------------------------------------------
# Directories
SRC_DIR					:= src
OBJ_DIR					:= obj
LIB_DIR 				:= libraries

#------------------------------SRC/----------------------------------------------------

# Source directories (src/)
BUILDERS_DIR			:= $(SRC_DIR)/builders
ERROR_DIR				:= $(SRC_DIR)/error
LOGIC_DIR				:= $(SRC_DIR)/logic
MODEL_DIR				:= $(SRC_DIR)/model
SHARED_DIR				:= $(SRC_DIR)/shared

#---------------------------BUILDERS/--------------------------------------------------
# Directories (builders/)
MAP_BUILDER_DIR			:= $(BUILDERS_DIR)/map_builder

#Sum up
BUILDERS_DIRS			:= $(MAP_BUILDER_DIR)

#---------------------------LOGIC/--------------------------------------------------
# Directories (logic/)
GUI_DIR					:= $(LOGIC_DIR)/gui

#Sum up
LOGIC_DIRS				= $(GUI_DIRS)

#---------------------------MODEL/--------------------------------------------------
# Directories (model/)
APP_CLASS_DIR			:= $(MODEL_DIR)/app
COLOR_CLASS_DIR			:= $(MODEL_DIR)/color
DIRECTION_CLASS_DIR		:= $(MODEL_DIR)/direction
GAME_CLASS_DIR			:= $(MODEL_DIR)/game
MAP_CLASS_DIR			:= $(MODEL_DIR)/map
PLAYER_CLASS_DIR		:= $(MODEL_DIR)/player
POINT_CLASS_DIR			:= $(MODEL_DIR)/point
SURFACE_CLASS_DIR		:= $(MODEL_DIR)/surface
WALL_CLASS_DIR			:= $(MODEL_DIR)/wall

#Sum up
MODEL_DIRS				= $(APP_CLASS_DIR) \
							$(COLOR_CLASS_DIR) \
							$(DIRECTION_CLASS_DIR) \
							$(GAME_CLASS_DIR) \
							$(MAP_CLASS_DIR) \
							$(PLAYER_CLASS_DIR) \
							$(POINT_CLASS_DIR) \
							$(SURFACE_CLASS_DIR) \
							$(WALL_CLASS_DIR)

#---------------------------LOGIC/GUI/--------------------------------------------------
# Directories (logic/gui/)
CANVAS_DIR				:= $(GUI_DIR)/canvas
EVENT_HANDLERS_DIR		:= $(GUI_DIR)/event_handlers
MINIMAP_DIR				:= $(GUI_DIR)/minimap
WINDOW_DIR				:= $(GUI_DIR)/window
MOVEMENTS_DIR			:= $(GUI_DIR)/movements

#Sum up
GUI_DIRS				= $(CANVAS_DIR) \
							$(EVENT_HANDLERS_DIR) \
							$(MINIMAP_DIR) \
							$(WINDOW_DIR) \
							$(MOVEMENTS_DIR)


#----------------------------------SUM UP-----------------------------------------------
SRC_DIRS				:= $(SRC_DIR) \
							$(BUILDERS_DIRS) \
							$(ERROR_DIR) \
							$(LOGIC_DIRS) \
							$(MODEL_DIRS) \
							$(SHARED_DIR)

############################################################################################
############################################################################################
############################################################################################

#-----------------------SOURCE FILES------------------------------------------------------------
# Sources
C_FILES 				:= $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
HEADERS 				:= $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.h))

# Objects
OBJ     				:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(C_FILES)))

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

# List of all library directories
LIB_DIRS				:= $(MLX_LIB_DIR) \
							$(STRING_LIB_DIR) \
							$(LIST_LIB_DIR) \
							$(GNL_LIB_DIR) \
							$(CONVERTER_LIB_DIR) \
							$(FILE_LIB_DIR) \
							$(MEMORY_LIB_DIR)

#-----------------------LIBRARIES--------------------------------------------------------
# Libraries
MLX_LIB     			:= $(MLX_LIB_DIR)/libmlx42.a
STRING_LIB				:= $(STRING_LIB_DIR)/ft_string.a
LIST_LIB				:= $(LIST_LIB_DIR)/list.a
GNL_LIB					:= $(GNL_LIB_DIR)/get_next_line.a
CONVERTER_LIB			:= $(CONVERTER_LIB_DIR)/converter.a
FILE_LIB				:= $(FILE_LIB_DIR)/file.a
MEMORY_LIB				:= $(MEMORY_LIB_DIR)/ft_memory.a

# List of all libraries
LIBRARIES				:= $(MLX_LIB) \
							$(STRING_LIB) \
							$(LIST_LIB) \
							$(GNL_LIB) \
							$(CONVERTER_LIB) \
							$(FILE_LIB) \
							$(MEMORY_LIB)

#-----------------------COLORS-----------------------------------------------------------
# Colors for Output
GREEN					:= \033[0;32m
RED						:= \033[0;31m
BLUE					:= \033[0;34m
YELLOW					:= \033[0;33m
RESET					:= \033[0m

#-----------------------RULES------------------------------------------------------------
vpath %.c $(SRC_DIRS)
vpath %.h $(SRC_DIRS)

# Default Target
all: $(MLX_LIB) $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

# Compile Object Files
$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile custom libraries
%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null

# Compile mlx42 library
$(MLX_LIB):
	@if [ ! -d "$(MLX_REPO_DIR)" ] || [ -z "$$(ls -A $(MLX_REPO_DIR))" ]; then \
		echo "$(YELLOW)>> Initializing MLX42 submodule...$(RESET)"; \
		git submodule update --init --recursive $(MLX_REPO_DIR) > /dev/null; \
	fi
	@echo "$(YELLOW)>> Building MLX42...$(RESET)"
	@cmake -S $(MLX_REPO_DIR) -B $(MLX_REPO_DIR)/build > /dev/null
	@cmake --build $(MLX_REPO_DIR)/build > /dev/null

# Compile cub3d.a file to use inside tests/ folder
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

# Print all of the source (.c, .h) files list, to help prepare makefile for an eval
print:
	@echo $(notdir $(C_FILES)) | tr ' ' '\n' > c_files.txt
	@echo $(notdir $(HEADERS)) | tr ' ' '\n' > headers.txt