all: gymnast

gymnast: gymnast.cpp
	g++ -std=c++11 -o gymnast gymnast.cpp

.PHONY: clean
clean:
	rm -f gymnast
