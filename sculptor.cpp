#include <Sculptor.h>

Sculptor::Sculptor()
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
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].alpha = alpha;
    
    isOn = true;

    //a fazer
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].alpha = alpha;

    isOn = false;

    //a fazer
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{

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
