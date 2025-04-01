CXX = g++
CXXFLAGS = -std=c++11 -Wall

LIBS = -lssl -lcrypto

SOURCES = main.cpp fraudDetection.cpp rateLimiter.cpp TransactionData.cpp TransactionLogger.cpp helperFunctions.cpp decryption.cpp encryption.cpp

OBJECTS = $(SOURCES:.cpp=.o)

EXEC = executable

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS) $(LIBS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -f $(OBJECTS) $(EXEC)
