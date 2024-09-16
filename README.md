## Towns game
# What is Towns Game
Towns game is a simple progect, made by Mikhail Grechishnikov, a Mephi student
It contains a cpp program and library for playing towns game
# How to get Towns Game
```
git clone https://github.com/Duhamster456/Towns-Game.git
git submodule init
git submodule update
```
# How to use it
Go to build directory, then launch a builing makefile, which will launch cmake
```
cd build
make -f start
```

Now there should be 3 executables in build directory: lab1, lab1_cstr and tests

lab1 and lab1_cstr are the programs for playing the game, and tests is, obviosly a program that runs tests for towns game library

for testing with coverage report run

```
cd build
make -f test start
```