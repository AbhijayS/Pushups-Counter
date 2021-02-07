pushupsmake: pushups.o
	gcc pushups.o -std=c99 -Wall -Wextra -Wpedantic -o pushups 

.PHONY: clean

clean:
	rm -f pushups

