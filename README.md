# Filler
Filler is an algorithmic game which consists in filling a grid of a known size in advance with pieces of random size and shapes, without the pieces being stacked more than one square above each other and without them exceeding the grid. If one of these conditions is not met, the game stops.

# How to start
git clone https://github.com/MirRinat/Filler.git

cd Filler

make
# How to play
cd resouces

./filler_vm -f maps/map01 -p1 ../bglinda.filler -p2 players/superjeannot.filler

   -p1 --player1        use filler binary as a first player
   
   -p2 --player2        use filler binary as a second player
   
   -f  --file           use a map file (required)


