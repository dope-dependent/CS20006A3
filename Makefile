BUILD_DIR ?= ./.out
OUTPUT_DIR ?= ./Outputs/

CXX := g++
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' ! -name '_*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

all: Application
	./Application

test:	ApplicationTest
	./ApplicationTest

unit-test:	UnitTest
	./UnitTest

all-text: Application 
	./Application > AppOutput.txt

test-text:	ApplicationTest
	./ApplicationTest > AppTestOutput.txt 

unit-test-text: UnitTest
	./UnitTest > UnitTest.txt

Application: $(OBJS) _App.cpp Makefile
	$(CXX) $(OBJS) _App.cpp -o $@  	

$(BUILD_DIR)/%.cpp.o: %.cpp %.h
	$(MKDIR_P) $(dir $@)
	$(CXX) -c $< -o $@

ApplicationTest: $(OBJS) _AppTest.cpp Makefile
	$(CXX) $(OBJS) _AppTest.cpp -o $@  	

$(BUILD_DIR)/%.cpp.o: %.cpp %.h
	$(MKDIR_P) $(dir $@)
	$(CXX) -c $< -o $@

UnitTest: $(OBJS) _UnitTest.cpp Makefile
	$(CXX) $(OBJS) _UnitTest.cpp -o $@  	

$(BUILD_DIR)/%.cpp.o: %.cpp %.h
	$(MKDIR_P) $(dir $@)
	$(CXX) -c $< -o $@


.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
	
MKDIR_P ?= mkdir -p