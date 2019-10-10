#include <Sculptor.h>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

   /*Sistema numérico na seleção do tipo de escultura sendo reaizada
   * t = 1: preencher posição;
   * t = 2: apagar posição;
   * t = 3: preencher retangulo;
   * t = 4: apagar retangulo;
   * t = 5: preencher esfera;
   * t = 6: apagar esfera;
   * t = 7: preencher elipsoide;
   * t = 8: apagar elipsoide;
   */ 

void FiguraGeometrica :: draw(Sculptor &t)
{
    if(t==1){
    }
    else if(t==2){
    }
    else if(t==3){
    }
    else if(t==4){
    }
    else if(t==5){
    }
    else if(t==6){
    }
    else if(t==7){
    }
    else if(t==8){
    }
    else{
        cout>>"inválido!">>endl;
    }
}

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
   nx=_nx; ny=_ny; nz=_nz; //inicia as dimensoes da matriz 3D

   if(_nx<=0||_ny<=0||_nz<=0){
       _nx=_ny=_nz=0;
   }
   v=new Voxel**[_nx];
   if(v==nullptr){
       cout<<"Erro na alocacao."<<endl;
       exit(0);
   }
   v[0]=new Voxel*[_nx*_ny];
   if(v[0]==nullptr){
       cout<<"Erro na alocacao."<<endl;
       exit(0);
   }
   v[0][0]=new Voxel[_nx*_ny*_nz];
   if(v[0][0]==nullptr){
       cout<<"Erro na alocacao."<<endl;
       exit(0);
   }
   for(int i=0; i< _nx; i++)
   {
       if (i<(_nx-1))
       {
           v[i+1] = v[i]+_ny;
       }
       for(int j=1; j< _ny; j++)
       {
           v[i][j] = v[i][j-1]+_nz;
           if(j==_ny-1 && i!=(_nx-1))
           {
               v[i+1][0] = v[i][j]+_nz;
           }
       }
   }
   for(int i = 0; i < _nx; i++){
       for(int j = 0; j < _ny; j++){
           for(int k = 0; k < _nz; k++){
               v[i][j][k].isOn = false;
           }
       }
   }
}

// a variável booleana isOn indicará se a posição está ou não preenchida

Sculptor::~Sculptor()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

/*Na próxima etapa vamos setar as cores da escultura.
* r(red) representa o vermelho,
* g(green) representa o verde,
* b(blue) representa o azul,
* e alpha representa o nível de transparência.
*/

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    if(r>1 || r<0 || g>1 || g<0 || b>1 || b<0 || alpha >1 || alpha<0){
        exit(1);
    }
    else{
        this -> r = r;
        this -> g = g;
        this -> b = b;
        a = alpha;
    }
}

void Sculptor::putVoxel(int x, int y, int z)
{
    if(x<0 || y <0 || z<0 || x>nx || y>ny || z>nz){
       exit(1);
    }
    else{
        v[x][y][z].isOn = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    if(x<0 || y <0 || z<0 || x>nx || y>ny || z>nz){
        exit(1);
    }
    else{
      v[x][y][z].isOn = false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    if(x0<0 || x1>nx || y0<0|| y1>ny || z0<0 || z1>nz){
       exit(1);
    }
    else{
        for (int i = x0; i<=x1; i++){
            for (int j = y0; j<=y1; j++){
                for (int k = z0; k<=z1; k++){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    if(x0<0 || x1>nx || y0<0|| y1>ny || z0<0 || z1>nz){
       exit(1);
    }
    else{
        for (int i = x0; i<=x1; i++){
            for (int j = y0; j<=y1; j++){
                for (int k = z0; k<=z1; k++){
                    v[i][j][k].isOn = false;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = xcenter-radius; i<nx; i++){
            for(int j = ycenter-radius; j<ny; j++){
                for(int k = zcenter-radius; k<nz; k++){
                if(((i-xcenter)*(i-xcenter) + (j-ycenter)*(j-ycenter) + (k-zcenter)*(k-zcenter))<= (radius*radius)){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = xcenter-radius; i<nx; i++){
        for(int j = ycenter-radius; j<ny; j++){
            for(int k = zcenter-radius; k<nz; k++){
                if(((i-xcenter)*(i-xcenter) + (j-ycenter)*(j-ycenter) + (k-zcenter)*(k-zcenter))<= (radius*radius)){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = xcenter-rx; i<=xcenter+rx; i++)
    {
        for(int j = ycenter-ry; j<=ycenter+ry; j++)
        {
            for(int k = zcenter-rz; k<=zcenter+rz; k++)
            {
               if((((float)((i-xcenter)*(i-xcenter))/(float)(rx*rx))+((float)((j-ycenter)*(j-ycenter))/(float)(ry*ry))+((float)((k-zcenter)*(k-zcenter))/(float)(rz*rz)))<=1.0){
                        v[i][j][k].r = r;
                        v[i][j][k].g = g;
                        v[i][j][k].b = b;
                        v[i][j][k].a = a;
                        v[i][j][k].isOn = true;
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = xcenter-rx; i<=xcenter+rx; i++)
    {
        for(int j = ycenter-ry; j<=ycenter+ry; j++)
        {
            for(int k = zcenter-rz; k<=zcenter+rz; k++)
            {
               if((((float)((i-xcenter)*(i-xcenter))/(float)(rx*rx))+((float)((j-ycenter)*(j-ycenter))/(float)(ry*ry))+((float)((k-zcenter)*(k-zcenter))/(float)(rz*rz)))<=1.0){
                        v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void Sculptor::writeOFF(char* filename)
{
    ofstream fout;
    int Nvertices=0;
    int Nfaces=0;
    int aux=0;

    fout.open(filename);

    if(fout.is_open()){
        cout << "arquivo OFF foi aberto\n";
    }
    else{
        cout << "arquivo OFF nao foi aberto\n";
        exit(1);
    }

    fout<<"OFF"<<endl;

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                    Nvertices=Nvertices+8;
                    Nfaces=Nfaces+6;
                }
            }
        }
    }

    fout<<Nvertices<<" "<<Nfaces<<" "<<0<<endl;

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                        fout<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        fout<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        fout<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        fout<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        fout<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                        fout<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        fout<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        fout<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                }
            }
        }
    }

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                    fout<<4<<" "<<aux+0<<" "<<aux+3<<" "<<aux+2<<" "<<aux+1<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+4<<" "<<aux+5<<" "<<aux+6<<" "<<aux+7<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+0<<" "<<aux+1<<" "<<aux+5<<" "<<aux+4<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+0<<" "<<aux+4<<" "<<aux+7<<" "<<aux+3<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+3<<" "<<aux+7<<" "<<aux+6<<" "<<aux+2<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+1<<" "<<aux+2<<" "<<aux+6<<" "<<aux+5<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    aux=aux+8;
                }
            }
        }
    }

    if(fout.is_open()){
        cout << "arquivo OFF salvo"<<endl;
    }
}

