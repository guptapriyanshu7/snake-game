TARGET := bin/app

SOURCES := $(shell find src -type f)
OBJECTS := $(patsubst src/%, build/%, $(SOURCES:.cpp=.o))
DEPS := $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS)
	@mkdir -p bin
	g++ $^ -o $(TARGET)

build/%.o: src/%.cpp
	@mkdir -p $(shell dirname $@)
	g++ -MMD -c $< -o $@

clean:
	rm -rf build bin

.PHONY: clean

-include $(DEPS)
