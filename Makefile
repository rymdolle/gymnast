all: main.cpp
	g++ -std=c++11 -o gymnast main.cpp

experimental: main.cpp
	g++ -std=c++17 -o gymnast main.cpp -DEXPERIMENTAL

clean:
	rm -f gymnast
