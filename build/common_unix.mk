.PHONY : all
all: build.ninja
	ninja
clean: CMakeCache.txt
	ninja clean
	rm CMakeCache.txt
	rm build.ninja
	rm rules.ninja
	rm cmake_install.cmake
	rm -r CMakeFiles
	rm -r Game
	rm -r IndieLib
