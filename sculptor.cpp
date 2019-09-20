#include <Sculptor.h>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{

}

~Sculptor()
{

}

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> alpha = alpha;

    //pronto
}

void Sculptor::putVoxel(int x, int y, int z)
{
    isOn.v[x][y][z] = true;
    r.v[x][y][z] = r;
    g.v[x][y][z] = g;
    b.v[x][y][z] = b;
    alpha.v[x][y][z] = alpha;

    //a fazer
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    isOn.v[x][y][z] = false
    r.v[x][y][z] = 0;
    g.v[x][y][z] = 0;
    b.v[x][y][z] = 0;
    alpha.v[x][y][z] = 0;

    //a fazer
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i = x0; i <= x1; i++)
    {
        for(int j = y0; j <= y1; j++)
        {
            for(int k = z0; k <= z1; k++)
            {
                desenho.putVoxel(i, j, k);
            }
        }
    }
    
    //a fazer
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i = x0; i <= x1; i++)
    {
        for(int j = y0; j <= y1; j++)
        {
            for(int k = z0; k <= z1; k++)
            {
                desenho.cutVoxel(i, j, k);
            }
        }
    }
    
    //a fazer
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{

}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{

}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{

}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{

}

void Sculptor::writeOFF(char *filename)
{

}
