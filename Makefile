APP_NAME = geometry
LIB_NAME = libgeometry
TEST_NAME = mytests

CFLAGS =   -Wall -Werror -I$(SRC_DIR)/$(LIB_NAME) -I$(LIB_TEST)
CPPFLAGS = -I src -MP -MMD
LDFLAGS =
LDLIBS =
CXX = g++
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test
LIB_TEST = thirdparty

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

SRC_EXT = cpp

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

.PHONY: all
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: test
test: $(OBJ_DIR)/$(TEST_DIR)/mytests.o $(OBJ_DIR)/$(TEST_DIR)/main.o $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/libgeometry.a
	g++ $(CFLAGS) $^ -o $(BIN_DIR)/mytests -lm

obj/test/mytests.o: $(TEST_DIR)/mytests.cpp
	g++ -c $(CFLAGS) $< -o $@
	
obj/test/main.o: $(TEST_DIR)/main.cpp
	g++ -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;