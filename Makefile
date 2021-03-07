BUILD_DIR ?= ./.out

CXX := g++
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' ! -name '_*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

all: Application
	./Application

Application: $(OBJS) _App.cpp Makefile
	$(CXX) $(OBJS) _App.cpp -o $@  	

$(BUILD_DIR)/%.cpp.o: %.cpp %.h
	$(MKDIR_P) $(dir $@)
	$(CXX) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
	rm Application

MKDIR_P ?= mkdir -p