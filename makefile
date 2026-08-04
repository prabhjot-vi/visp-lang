CC := gcc
APP := visp-lang

SRC_DIR := ./src
BUILD_DIR := ./build

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

INC_FLAG := $(addprefix -I,$(SRC_DIR))

CFLAGS := $(INC_FLAG) -g -std=c11 \
	-Wall -Wextra -Wpedantic -Werror \
	-Wconversion -Wshadow -Wformat=2 -Wundef -fstack-protector-strong

build: $(BUILD_DIR)/$(APP)

run: build
	./$(BUILD_DIR)/$(APP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(APP): $(OBJS)
	$(CC) $^ -o $@

clean:
	rm -r $(BUILD_DIR)

.PHONY: build run clean all
