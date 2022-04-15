CXX?=g++
CXXFLAGS+= -std=c++17 -O3 -Wall -Wextra -I.

SOURCEDIR=src
OBJECTSDIR=obj

SOURCES=$(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS=$(SOURCES:$(SOURCEDIR)/%.cpp=$(OBJECTSDIR)/%.o)

sim: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECTSDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJECTS): | $(OBJECTSDIR)

$(OBJECTSDIR):
	mkdir $@

clean:
	del $(OBJECTSDIR)\*.o sim.exe

cleanData:
	del data\*.bin

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<