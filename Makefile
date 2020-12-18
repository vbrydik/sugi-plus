# Reference:
# https://stackoverflow.com/questions/7004702

TARGET = exec

SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = include

CC     = g++
LINKER = g++

CFLAGS = -w -g -I./$(INCDIR)/ -I/usr/include/lua5.3
LFLAGS = -lGL -lGLU -lGLEW -lSDL2 -lSDL2main -lm -llua5.3

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.hpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

rm = rm -r -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "LINKER  $(@)"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC      "$<


setup:
	@mkdir $(BINDIR)
	@mkdir $(OBJDIR)

run:
	@$(BINDIR)/$(TARGET)

clean:
	@$(rm) $(OBJECTS)
	@echo "$(rm) $(OBJECTS)"

remove:
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "$(rm) $(BINDIR)/$(TARGET)"