#include "Geometry.h"
#include "EasyMesh.h"


int main(int argc, char *argv[])
{
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
    std::cout << "X = [" << std::endl;
    for (int i = 0; i < n_seg; i++)
    {
	const GeometryBM &seg = mesh.geometry(1, i);
	std::cout << mesh.point(seg.boundary(0))[0] << "\t" << mesh.point(seg.boundary(1))[0] << std::endl;;
    }
    std::cout << "];" << std::endl;
    std::cout << "Y = [" << std::endl;
    for (int i = 0; i < n_seg; i++)
    {
	const GeometryBM &seg = mesh.geometry(1, i);
	std::cout << mesh.point(seg.boundary(0))[1] << "\t" << mesh.point(seg.boundary(1))[1] << std::endl;;
    }
    std::cout << "];" << std::endl;
    std::cout << "plot(X',Y','b')" << std::endl;
    return 0;
};
