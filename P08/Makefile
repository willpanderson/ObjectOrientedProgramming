CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: testmonkey

testmonkey: main.o mainwin.o animal.o dog .o shelter.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o animal.o shelter.o dog.o $(GTKFLAGS) -o testmonkey

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

animal.o: main.cpp mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c animal.cpp -o animal.o
  
dog.o: dog.cpp *.h
	$(CXX) $(CXXFLAGS) -c dog.cpp -o dog.o

shelter.o: shelter.cpp *.h
	$(CXX) $(CXXFLAGS) -c shelter.cpp -o shelter.o
	
clean:
	rm -f *.o *.gch *.ii *.s a.out testmonkey
