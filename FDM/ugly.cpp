#include <iostream>
#include <cmath>

const double PI = (std::atan(1.0) * 4.0);

double source(double x, double y);

double u_b(double x, double y);

double source(double x, double y)
{
    return 2.0 * PI * PI * std::sin(PI * x) * std::sin(PI * y);
};

double u_b(double x, double y)
{
    return std::sin(PI * x) * std::sin(PI * y);
};

int main(int argc, char *argv[])
{
    double x0 = 0.0;
    double y0 = 0.0;
    double x1 = 1.0;
    double y1 = 1.0;

    int N = 20;
    double h = (x1 - x0) / (N - 1);
    int n = (N - 2) * (N - 2);

    double A[n][n];
    double f[n];

    for (int i = 0; i < n; i++)
    {
	for (int j = 0; j < n; j++)
	    A[i][j] = 0;
	f[i] = 0;
    }

    // left, bottom corner;
    A[0][0] = 4;
    A[0][1] = -1;
    A[0][N - 2] = -1;
    f[0] = source(h, h) + u_b(0, h) + u_b(h, 0);
    // bottom boundary;
    for (int j = 1; j < N - 3; j++)
    {	
	A[j][j] = 4;
	A[j][j - 1] = -1;
	A[j][j + 1] = -1;
	A[j][j + N - 2] = -1;
	f[j] = source((j + 1) * h, h) + u_b((j + 1) * h, 0);
    }
    // right, bottom corner;
    A[N - 3][N - 3] = 4;
    A[N - 3][N - 4] = -1;
    A[N - 3][2 * N - 5] = -1;
    f[N - 3] = source((N - 2) * h, h) + u_b((N - 2) * h, 0) + u_b((N - 1) * h, h);
   
    for (int i = 1; i < N - 3; i++)
    {
    	// left boundary.
    	int idx = i * (N - 2);
    	A[idx][idx] = 4;
    	A[idx][idx + 1] = -1;
    	A[idx][idx + N - 2] = -1;
    	A[idx][idx - N + 2] = -1;
	f[idx] = source(h, (i + 1) * h) + u_b(0, (i + 1) * h);
    	for (int j = 1; j < N - 3; j++)
    	{
    	    // inner.
    	    int idx = i * (N - 2) + j;
    	    A[idx][idx] = 4;
    	    A[idx][idx + 1] = -1;
    	    A[idx][idx - 1] = -1;
    	    A[idx][idx + N - 2] = -1;
    	    A[idx][idx - N + 2] = -1;
	    f[idx] = source((j + 1) * h, (i + 1) * h);
    	}
    	// right boundary.
    	idx = i * (N - 2) + N - 3;
    	A[idx][idx] = 4;
    	A[idx][idx - 1] = -1;
    	A[idx][idx + N - 2] = -1;
    	A[idx][idx - N + 2] = -1;
	f[idx] = source((N - 2) * h, (i + 1) * h) + u_b((N - 1) * h, (i + 1) * h);
    }
    
    // left, up corner;
    int idx = (N - 2) * (N - 3);
    A[idx][idx] = 4;
    A[idx][idx + 1] = -1;
    A[idx][idx - N + 2] = -1;
    f[idx] = source(h, (N - 2) * h) + u_b(0, (N - 2) * h) + u_b(h, (N - 1) * h);
    // up boundary;
    for (int j = 1; j < N - 3; j++)
    {	int idx = (N - 2) * (N - 3) + j;
    	A[idx][idx] = 4;
    	A[idx][idx - 1] = -1;
    	A[idx][idx + 1] = -1;
    	A[idx][idx - N + 2] = -1;
	f[idx] = source((j + 1) * h, (N - 2) * h) + u_b((j + 1) * h, (N - 1) * h);
    }
    // right, up corner;
    idx = (N - 2) * (N - 2) - 1;
    A[idx][idx] = 4;
    A[idx][idx - 1] = -1;
    A[idx][idx - N + 2] = -1;
    f[idx] = source((N - 2) * h, (N - 2) * h) + u_b((N - 1) * h, (N - 2) * h) + u_b((N - 2) * h, (N - 1) * h);
    std::cout << "A = [" << std::endl;
    for (int i = 0; i < n; i++)
    {
	for (int j = 0; j < n; j++)
	    std::cout << A[i][j] << "\t";
	std::cout << std::endl;
    }
    std::cout << "];" << std::endl;
    std::cout << "f = [" << std::endl;
    for (int i = 0; i < n; i++)
	std::cout << f[i] << std::endl;
    std::cout << "];" << std::endl;
    return 0;
};
