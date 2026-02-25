# --- Setup ---
CXX      := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -g
TARGET   := automate_proc

# --- File Discovery ---
# This automatically finds all .cpp files in your current folder
SRCS     := $(wildcard *.cpp)
OBJS     := $(SRCS:.cpp=.o)

# --- Rules ---

.PHONY: all clean run

all: $(TARGET) ## Compile the entire project

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build successful: $(TARGET)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all ## Compile and immediately run the program
	./$(TARGET)

clean: ## Remove objects and executable
	rm -f $(OBJS) $(TARGET)
	@echo "Cleanup complete."