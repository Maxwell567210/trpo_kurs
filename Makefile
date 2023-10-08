APP_NAME = main
LIB_NAME = lib

SFML_FLAGS = -lsfml-graphics -lsfml-system -lsfml-window
CFLAGS = -I src/lib
DEPSFLAGS = -MMD
CC = g++

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

APP_SOURCES = $(wildcard $(SRC_DIR)/$(APP_NAME)/*.cpp)
APP_OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(APP_SOURCES))

LIB_SOURCES = $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.cpp)
LIB_OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(LIB_SOURCES))



$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $^ $(SFML_FLAGS)

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $< 



run: $(APP_PATH)
	./bin/main

clean:
	$(RM) $(APP_PATH) $(OBJ_DIR)/*/*/*.[aod]