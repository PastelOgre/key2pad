CXX ?= g++
INCLUDE_PATHS := -Isrc
CXXFLAGS ?= -std=c++17 -Wall -Wextra $(INCLUDE_PATHS)
LDFLAGS ?= -lsetupapi

ifeq ($(OS),Windows_NT)
EXE_EXT := .exe
else
EXE_EXT :=
endif

RELEASE_DIR := bin/release
DEBUG_DIR := bin/debug

# Recursive wildcard function
rwildcard = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

# Find all .cpp files recursively
SRC := $(call rwildcard,src,*.cpp)
TARGET := $(RELEASE_DIR)/key2pad$(EXE_EXT)
DEBUG_TARGET := $(DEBUG_DIR)/key2pad$(EXE_EXT)

.PHONY: all debug clean

all: CXXFLAGS += -O3
all: $(TARGET)

debug: CXXFLAGS += -g -O0
debug: $(DEBUG_TARGET)

$(TARGET): $(SRC)
	mkdir -p $(RELEASE_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(DEBUG_TARGET): $(SRC)
	mkdir -p $(DEBUG_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	rm -rf bin/
