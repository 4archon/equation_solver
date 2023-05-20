solver: main.cpp analyser.cpp file_rw.cpp plotter.cpp quadeq.cpp solver.cpp
	mkdir program
	g++ main.cpp analyser.cpp file_rw.cpp plotter.cpp quadeq.cpp solver.cpp -o program/solver
