CXXFLAGS = --std=c++17

train : main.o stock.o coach.o locomotive.o train.o
	$(CXX) $(CXXFLAGS) main.o stock.o coach.o locomotive.o train.o -o train
	$(info Linking...)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
	$(info Compiling...)

stock.o: stock.cpp
	$(CXX) $(CXXFLAGS) -c stock.cpp -o stock.o
	$(info Compiling...)

locomotive.o: locomotive.cpp
	$(CXX) $(CXXFLAGS) -c locomotive.cpp -o locomotive.o
	$(info Compiling...)

coach.o: coach.cpp
	$(CXX) $(CXXFLAGS) -c coach.cpp -o coach.o
	$(info Compiling...)

train.o: train.cpp
	$(CXX) $(CXXFLAGS) -c train.cpp -o train.o
	$(info Compiling...)


clean:
	rm -fd *.o *.gch ~* a.out lines
