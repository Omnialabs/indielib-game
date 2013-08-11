.PHONY : all
all: Makefile
	make
clean: CMakeCache.txt
	cmd /c "del CMakeCache.txt Makefile cmake_install.cmake"
	cmd /c "rmdir /Q /S CMakeFiles"
	cmd /c "rmdir /Q /S Game"
	cmd /c "rmdir /Q /S IndieLib"
