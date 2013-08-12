include ../../common_unix.mk

build.ninja:
	cmake ../../../../ -G "Ninja" -DCMAKE_BUILD_TYPE=Release
