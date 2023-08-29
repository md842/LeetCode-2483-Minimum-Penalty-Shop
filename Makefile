CFLAGS = -std=gnu17 -Wall -O2 -pipe -fno-plt -fPIC
CPPFLAGS = -Wall -O2 -pipe -fno-plt -fPIC

default: minimum_penalty_cpp

minimum_penalty: minimum_penalty.c
	$(CC) $(CFLAGS) minimum_penalty.c -o minimum_penalty

minimum_penalty_cpp: minimum_penalty.cpp
	g++ $(CPPFLAGS) minimum_penalty.cpp -o minimum_penalty

.PHONY: clean
clean:
	rm -f minimum_penalty
