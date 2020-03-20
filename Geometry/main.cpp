#include "Geometry.h"
#include "EasyMesh.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::ofstream output("test.m");
    EasyMesh mesh;
    mesh.readData("D");
    Mesh<2, 2> (mesh).writeData("E");
    int n_pnt = mesh.n_point();
    std::cout << "No. of points: " << n_pnt << std::endl;
    for (int i = 0; i < n_pnt; i++)
    {
    	const Point<2> &pnt = mesh.point(i);
    	std::cout << "(" << pnt[0] << ", " << pnt[1] << ")" << std::endl;
    }
    int n_seg = mesh.n_geometry(1);
    std::cout << "No. of segments: " << n_seg << std::endl;
    for (int i = 0; i < n_seg; i++)
    {
    	const GeometryBM &seg = mesh.geometry(1, i);
    	std::cout << seg.boundary(0) << " - " << seg.boundary(1) << std::endl;
    }

    // draw in matlab.
    output << "X = [" << std::endl;
    for (int i = 0; i < n_seg; i++)
    {
	const GeometryBM &seg = mesh.geometry(1, i);
	output << mesh.point(seg.boundary(0))[0] << "\t" << mesh.point(seg.boundary(1))[0] << std::endl;;
    }
    output << "];" << std::endl;
    output << "Y = [" << std::endl;
    for (int i = 0; i < n_seg; i++)
    {
	const GeometryBM &seg = mesh.geometry(1, i);
	output << mesh.point(seg.boundary(0))[1] << "\t" << mesh.point(seg.boundary(1))[1] << std::endl;;
    }
    output << "];" << std::endl;
    output << "plot(X',Y','b')" << std::endl;
    output << "axis equal;" << std::endl;
    output.close();
    return 0;
};
