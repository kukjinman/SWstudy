NY: all install clean


all: install

install:
	if [ ! -d build ]; then mkdir build && cd build && cmake .. ; fi;
	cd build && make -j4 && make install

clean:
	rm -rf build

