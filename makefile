# $@ : nom de la cible
# $^ : listes des dépendances
# $< : nom de la première dépendance

CXX=g++
CXXFLAGS=-Wall
RM=rm -f

play: timetime.o move.o board.o snake.o food.o background.o game.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o : main.cpp game.cpp
game.o: game.cpp timetime.cpp background.h
snake.o: snake.cpp snake.h move.h
move.o: move.cpp move.h
food.o: food.cpp food.h snake.h
background: background.cpp background.h food.h board.h
board.o: board.cpp board.h
timetime.o: timetime.cpp

%.o: %.cpp; $(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) main.o timetime.o game.o snake.o move.o food.o move.o board.o background.o


