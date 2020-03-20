#include "Geometry.h"
#include "EasyMesh.h"

int main(int argc, char *argv[])
{
    EasyMesh mesh;
    mesh.readData("D");
    Mesh<2, 2> (mesh).writeData("E");
    return 0;
};
