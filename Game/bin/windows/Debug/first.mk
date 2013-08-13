include ../../common_windows.mk

Makefile:
	cmake ../../../../ -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=DEBUG
