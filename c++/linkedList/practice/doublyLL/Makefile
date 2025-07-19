CC = clang++
CFLAGS = -Wall -Wextra -std=c++17 -g -O0

#Sanitizer flags for macOS
ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer
UBSAN_FLAGS = -fsanitize=undefined -fno-omit-frame-pointer
TSAN_FLAGS = -fsanitize=thread -fno-omit-frame-pointer

#target executables
TARGETS = main
 
#default target
all: $(TARGETS)

main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main

clean:
	rm -f $(TARGETS) main_asan main_ubsan
 
debug: main
	lldb ./main

#satitizer targets
asan: main_asan
	./main_asan
 
ubsan: main_ubsan
	./main_ubsan
 
#sanitizer builds
main_asan: main.cpp
	$(CC) $(CFLAGS) $(ASAN_FLAGS) -o $@ $<
 
main_ubsan: main.cpp
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) -o $@ $<
.PHONY:
	all clean debug asan ubsan