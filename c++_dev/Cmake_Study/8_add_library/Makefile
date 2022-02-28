NY: all install clean


all: install

install:
	if [ ! -d build ]; then mkdir build && 	echo " testing1" && cd build && cmake .. ; fi;
	cd build && make -j4 
	echo " testing2"

clean:
	rm -rf build

