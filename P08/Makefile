CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: massanimal

massanimal: main.cpp mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp $(GTKFLAGS) -o math

main: main.cpp mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp $(GTKFLAGS) -o math

mainwin: main.cpp mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp $(GTKFLAGS) -o math

animal: main.cpp mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp $(GTKFLAGS) -o math
  
dog: main.cpp mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp $(GTKFLAGS) -o math

shelter: main.cpp mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp $(GTKFLAGS) -o math
  
clean:
	rm -f *.o *.gch math
