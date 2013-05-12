CC=c++	-std=c++11	-stdlib=libc++
CXXOPTS=-Wall
LDFLAGS=-stdlib=libc++
BINDIR=build
TARGET=$(BINDIR)/stripcr

all:	$(TARGET)

$(TARGET):	stripcr.cpp
	$(CC)	$^	$(LDFLAGS)	-o	$@

clean:
	rm	-f	$(TARGET)
