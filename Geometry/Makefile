main : Geometry.1d.o Geometry.2d.o Geometry.3d.o Geometry.o Miscellaneous.o EasyMesh.o main.cpp 
	g++ -o main main.cpp Geometry.1d.o Geometry.2d.o Geometry.3d.o Geometry.o Miscellaneous.o EasyMesh.o -ldl

Geometry.1d.o : Geometry.1d.cpp
	g++ -c Geometry.1d.cpp

Geometry.2d.o : Geometry.2d.cpp
	g++ -c Geometry.2d.cpp

Geometry.3d.o : Geometry.3d.cpp
	g++ -c Geometry.3d.cpp

Geometry.o : Geometry.cpp
	g++ -c Geometry.cpp

Miscellaneous.o : Miscellaneous.cpp
	g++ -c Miscellaneous.cpp

EasyMesh.o : EasyMesh.cpp
	g++ -c EasyMesh.cpp

clean:
	rm *.o
	rm main
