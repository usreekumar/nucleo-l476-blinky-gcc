# Specifying the header file directories
INCS_DIR  = ./Core/Inc
INCS_DIR += ./Drivers/CMSIS/Inc
INCS_DIR += ./Drivers/CMSIS/Device/Inc
INCS_DIR += ./Libs/Inc

# Specifying the src file directories
SRCS_DIR  = ./Core/Src
SRCS_DIR += ./Libs/Src
SRCS_DIR += ./Drivers/CMSIS/Device/Src

# Specifying the build file directories
BUILD_DIR = ./build
EXECUTABLE = $(BUILD_DIR)/exe

# Use the gcc compiler
CC = /home/umamaheswaran/Embedded/tools/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc

#Adding -I flags before the include folders to let the compiler know the paths to search 
INCLUDES := $(addprefix -I, $(INCS_DIR))

# Getting all the files with .c extenstion in the source directories
# find is a shell cmd for searching the directory tree rooted at each given starting-point
# -name flag specfies the files to seach for. Here 'find' cmd will find all the *.c files in src directories, ie all src files
SRCS     := $(shell find $(SRCS_DIR) -name *.c)

# Compiling and creating an executable with the name exe in the build directoy
# $@ will give the name of the target => herr $@ will be replaced by ./build/exe
# -o flag is to specify the exeutable name and path
$(EXECUTABLE):
	$(CC) $(INCLUDES) $(SRCS) -o $@

# Running the executable file
run:
	./$(EXECUTABLE)
# clean will remove all the files in the BUILD_DIR
clean:
	rm -f $(BUILD_DIR)/*