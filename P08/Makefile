CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: massanimal

massanimal: main.o mainwin.o animal.o shelter.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o animal.o shelter.o dog.o $(GTKFLAGS) -o massanimal

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.o $(GTKFLAGS) -o mainwin.o

animal.o: main.cpp mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c animal.o -o animal.o
  
dog.o: dog.cpp *.h
	$(CXX) $(CXXFLAGS) -c dog.o -o dog.o

shelter.o: shelter.cpp *.h
	$(CXX) $(CXXFLAGS) -c shelter.o -o shelter.o
	
clean:
	rm -f *.o *.gch *.ii *.s a.out massanimal
