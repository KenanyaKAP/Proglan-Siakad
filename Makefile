CXX?=g++ 
CXXFLAGS+= -std=c++17 -O3 -Wall -Wextra -I.
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:src/%.cpp=obj/%.o)

obj/%.o: src/%.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

sim: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	del obj\*.o sim.exe

cleanData:
	del data\*.bin

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<