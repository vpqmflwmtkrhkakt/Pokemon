EXEC=Pokemon
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
CC=g++ -std=c++11 -g
CLIBS= -L/home/sasl/shared/main/c++/SFML-2.5.1/lib -lsfml-graphics  -lsfml-window -lsfml-system
INCDIR=-I//home/sasl/shared/main/c++/SFML-2.5.1/include
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(CLIBS)  -o $(EXEC)
%.o: %.cc
	$(CC) -Wall $(INCDIR)  -c $< -o $@

.depend: $(SOURCES)
	g++ -std=c++11 -MM $(SOURCES) > .depend
-include .depend
clean:
	rm -f $(OBJECTS) $(EXEC)