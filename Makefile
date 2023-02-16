#===============================================================================
#	TARGET
#===============================================================================
TARGET_NAME = output

#===============================================================================
#	USER DIRECTORIES
#===============================================================================
DIR_BUILD = ./build
DIR_SOURCES = ./src/
DIR_INCLUDES = ./include

#===============================================================================
#	COMPILER & FLAGS
#===============================================================================
CC = gcc
CFLAGS = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra

#===============================================================================
#	RESEARCH FILES
#===============================================================================
C_FILES = $(shell find $(DIR_SOURCES) -name '*.c')

#===============================================================================
#	BUILDING RULES
#===============================================================================
.PHONY: binary dir clean

binary: clean dir
	@$(CC) $(CFLAGS) $(C_FILES) -I$(DIR_INCLUDES) -o $(DIR_BUILD)/$(TARGET_NAME)
	@echo "> Binary génération success !"

dir:
	@echo "Création of build directory"
	@mkdir -p $(DIR_BUILD)

clean:
ifeq ("$(wildcard $(DIR_BUILD))", "")
	@echo "Previous build folder already removed"
else
	@echo "Start removing previous build folder"
	@rm -rf $(DIR_BUILD)
	@echo "Previous build folder removed"
endif
