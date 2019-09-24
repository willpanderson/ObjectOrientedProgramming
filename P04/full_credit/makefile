CXXFLAGS = --std=c++17

train : main.o stock.o coach.o locomotive.o train.o
	$(CXX) $(CXXFLAGS) -g main.o stock.o coach.o locomotive.o train.o -o train
	$(info Linking object files to train.exe...)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -g main.cpp -o main.o
	$(info Compiling main.cpp...)

stock.o: stock.cpp
	$(CXX) $(CXXFLAGS) -c -g stock.cpp -o stock.o
	$(info Compiling stock.cpp...)

locomotive.o: locomotive.cpp
	$(CXX) $(CXXFLAGS) -c -g locomotive.cpp -o locomotive.o
	$(info Compiling locomotive.cpp...)

coach.o: coach.cpp
	$(CXX) $(CXXFLAGS) -c -g coach.cpp -o coach.o
	$(info Compiling coach.cpp...)

train.o: train.cpp
	$(CXX) $(CXXFLAGS) -c -g train.cpp -o train.o
	$(info Compiling train.cpp...)

clean:
	rm -fd *.o *.gch ~* a.out train
