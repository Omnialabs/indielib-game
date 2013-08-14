.PHONY : all
all: Makefile
	make
	pwd
	cmd /c "copy /Y Game\Game.exe ."
	cmd /c "copy /Y IndieLib\libIndieLib.dll ."
	cmd /c "copy /Y IndieLib\common\dependencies\SDL-2.0\libSDL2.dll ."

clean: CMakeCache.txt
	cmd /c "del CMakeCache.txt Makefile cmake_install.cmake *.exe *.dll"
	cmd /c "rmdir /Q /S CMakeFiles"
	cmd /c "rmdir /Q /S Game"
	cmd /c "rmdir /Q /S IndieLib"
