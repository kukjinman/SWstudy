NY: all install clean


all: install

install:
	if [ ! -d build ]; then mkdir build && 	echo "ThreadPool" && cd build && cmake .. ; fi;
	cd build && make -j4 

clean:
	rm -rf build

