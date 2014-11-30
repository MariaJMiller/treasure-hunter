treasure-hunter
===============

Since th.cpp includes maze.cpp and ai.cpp, I do not think we need to
put them in this command line. Tell me if I'm wrong though...
I kept getting multiple definition errors until I did this.

Compile:

 g++ -std=c++11 th.cpp -o th

 Using makeFile:

 make -f makeFile