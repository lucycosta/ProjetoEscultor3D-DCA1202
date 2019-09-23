#include <iostream>
#include <Sculptor.h>

using namespace std;

int main()
{
    Sculptor desenho(20,20,20);
    desenho.setColor(0.9,0.1,0.1,0.7);
    desenho.putVoxel(3,3,3);
    desenho.cutVoxel(2,2,2);
    desenho.putBox(2,5,2,5,2,5);
    desenho.cutBox(1,5,1,5,1,5);
    desenho.putSphere(10,10,10,4);
    desenho.cutSphere(5,6,10,5);
    desenho.putEllipsoid(8,8,8,4,2,3);
    desenho.cutEllipsoid(5,5,5,3,4,5);
    desenho.writeOFF("desenho.off");

return 0;
}
