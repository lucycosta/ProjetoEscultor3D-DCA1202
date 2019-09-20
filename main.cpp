#include <iostream>
#include <Sculptor.h>

using namespace std;

int main()
{
int dim;
float r, g, b, alpha;
int x, y, z;
int x0, x1, y0, y1, z0, z1;
int xcenter, ycenter, zcenter, radius;


//tamanho do nosso espaço tridimensional
cout<<"Entre com a dimensão do espaço"<<endl;
cin>>dim;

Sculptor desenho(dim, dim, dim);

//cores e transparência
cout<<"Entre com as cores vermelho, verde e/ou azul"<<endl;
cin>>r>>g>>b;
cout<<"Entre com o nível de transparência"<<endl;
cin>>alpha;

desenho.setColor(r, g, b, alpha);

//adição de pontos
cout<<"Entre com a posição x do ponto"<<endl;
cin>>x;
cout<<"Entre com a posição y do ponto"<<endl;
cin>>y;
cout<<"Entre com a posição z do ponto"<<endl;
cin>>z;

desenho.putVoxel(x, y, z);

//remoção de pontos
cout<<"Entre com a posição x do ponto"<<endl;
cin>>x;
cout<<"Entre com a posição y do ponto"<<endl;
cin>>y;
cout<<"Entre com a posição z do ponto"<<endl;
cin>>z;

desenho.cutVoxel(x, y, z);

//adição de uma caixa
cout<<"Entre com o intervalo x da caixa"<<endl;
cin>>x0>>x1;
cout<<"Entre com o intervalo y da caixa"<<endl;
cin>>y0>>y1;
cout<<"Entre com o intervalo z da caixa"<<endl;
cin>>z0>>z1;

desenho.putBox(x0, x1, y0, y1, z0, z1);

//remoção de uma caixa
cout<<"Entre com o intervalo x da caixa"<<endl;
cin>>x0>>x1;
cout<<"Entre com o intervalo y da caixa"<<endl;
cin>>y0>>y1;
cout<<"Entre com o intervalo z da caixa"<<endl;
cin>>z0>>z1;

desenho.cutBox(x0, x1, y0, y1, z0, z1);

//adição de uma esfera
cout<<"Entre com o centro em x da esfera"<<endl;
cin>>xcenter;
cout<<"Entre com o centro em y da esfera"<<endl;
cin>>ycenter;
cout<<"Entre com o centro em z da esfera"<<endl;
cin>>zcenter;
cout<<"Entre com o raio"<<endl;
cin>>radius;

desenho.putSphere(xcenter, ycenter, zcenter, radius);
}
