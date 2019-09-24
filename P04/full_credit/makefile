CXXFLAGS = --std=c++17


train : main.o stock.o coach.o locomotive.o train.o
	$(CXX) $(CXXFLAGS) -g main.o stock.o coach.o locomotive.o train.o -o train
	$(info )
	$(info Linking object files to train.exe\n...)
	$(info )

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -g main.cpp -o main.o
	$(info )
	$(info Compiling main.cpp...)
	$(info )

stock.o: stock.cpp
	$(CXX) $(CXXFLAGS) -c -g stock.cpp -o stock.o
	$(info )
	$(info Compiling stock.cpp...)
	$(info )

locomotive.o: locomotive.cpp
	$(CXX) $(CXXFLAGS) -c -g locomotive.cpp -o locomotive.o
	$(info )
	$(info Compiling locomotive.cpp...)
	$(info )

coach.o: coach.cpp
	$(CXX) $(CXXFLAGS) -c -g coach.cpp -o coach.o
	$(info )
	$(info Compiling coach.cpp...)
	$(info )

train.o: train.cpp
	$(CXX) $(CXXFLAGS) -c -g train.cpp -o train.o
	$(info )
	$(info Compiling train.cpp...)
	$(info )

clean:
	rm -fd *.o *.gch ~* a.out train
	$(info )
	$(info Cleaning up the project folder...)
	$(info )