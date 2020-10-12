#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#define DIM 2

int main (int argc, char *argv[])
{
    int n_nodes = -1;
    int n_ele = -1;
    int n_sides = -1;
    std::string dummy;
    std::ifstream boundary;
    boundary.open("D.s");
    std::cin >> n_nodes >> n_ele >> n_sides;
    std::vector<std::vector<double> > points(n_nodes);
    std::vector<std::vector<double> >::iterator points_iterator = points.begin();
    std::vector<std::vector<double> >::iterator points_end = points.end();
    std::vector<std::vector<int> > sides(n_sides);
    std::vector<std::vector<int> >::iterator sides_iterator = sides.begin();
    std::vector<std::vector<int> >::iterator sides_end = sides.end();
    for (; points_iterator != points_end; points_iterator++)
	points_iterator->resize(DIM);
    for (; sides_iterator != sides_end; sides_iterator++)
	sides_iterator->resize(DIM);
    std::cin >> dummy;
    std::cin >> dummy;
    std::cin >> dummy;
    for (int i = 0; i < n_nodes; i++)
    {
	std::cin >> dummy;
	std::cin >> points[i][0] >> points[i][1];
	std::cin >> dummy;
    }
    boundary >> dummy;
    for (int i = 0; i < n_sides; i++)
    {
	boundary >> dummy;
	boundary >> sides[i][0] >> sides[i][1];
	boundary >> dummy;
	boundary >> dummy;
	boundary >> dummy;
    }
//    std::cout << "nodes: " << n_nodes << std::endl;
//    std::cout << "element:" << n_ele << std::endl;
//    std::cout << "sides:" << n_sides << std::endl;
//    std::cout << "dummy:" << dummy << std::endl;
    std::cout << "points=[" << std::endl;
    for (int i = 0; i < n_nodes; i++)
    {
	std::cout << points[i][0] << "," << points[i][1] << ";" <<std::endl;
    }
    std::cout << "];" << std::endl;
    std::cout << "hold on;" << std::endl;
    for (int i = 0; i < n_sides; i++)
    {
	int p1 = sides[i][0];
	int p2 = sides[i][1];
	
	std::cout << "plot([" << points[p1][0] << "," << points[p2][0] << "],"
		  << "[" << points[p1][1] << "," << points[p2][1] << "], 'b');" << std::endl;
    }
    return 0;
};
