#include <SFML/Graphics.hpp>
#include <unistd.h>

#include <stdlib.h>
using namespace std;

//Quita tener que poner sf:: a todo lo de SFML
using namespace sf;
//FUNCIONES
void funcionizquierda(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday);
void funcionderecha(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday);
void funcionarriba(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday);
void funcionabajo(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday);
//FUNCIONES 2
void funcionizquierda2(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday);
void funcionderecha2(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday);
void funcionarriba2(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday);
void funcionabajo2(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday);


//tamaño del charizard
int tam=90;
//Resolucion de mi pantalla
int dimensionx=800;
int dimensiony=600;
RenderWindow app(VideoMode(dimensionx, dimensiony), "TITULO DE LA VENTANA");
int main()
{
    //texturas donde se cargan las imagenes
    Texture texture;
    Texture texture2;
    int x=0, y=0; // coordenadas de pixeles del Charizard 1
    int x2=91, y2=91; // coordenadas de pixeles del Charizard 2
    //Se ejecuta la funcion dentro del if, y si esta no es exitosa el programa termina
    if (!texture.loadFromFile("FULL.png"))
    {
        return EXIT_FAILURE;
    }
    if (!texture2.loadFromFile("boom.png"))
    {
        return EXIT_FAILURE;
    }
    //Mejora la calidad de la textura cargada
    texture.setSmooth(true);
    texture2.setSmooth(true);
    //Se crea un sprite donde se carga la imagen guardada
    Sprite sprite(texture);
    //Se crea un sprite donde se carga una segunda imagen guardada
    Sprite sprite2(texture2);
    //Mientras la pantalla este abierta todo lo de adentro esta ejecutandose
    while (app.isOpen())
    {
        //Se declara un evento
        Event event;
        //Mientras hay eventos pendientes
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
            {
                app.close();
            }
            //Si S o s se presiona
            if(Keyboard::isKeyPressed(Keyboard::BackSpace))
            {
                //Borra todo lo que estaba en pantalla (Resetea la ventana)
                app.clear();
                x=0;
                y=0;
                x2=91;
                y2=91;
            }

            //COlISION DE CHARIZARD 1 CON CHARIZARD 2 EN BASE DONDE INICIAN SUS RECTANGULOS
            //colilision teorica
            if((x==x2 and y==y2) or (y+90==y2 and x==x2+90) or x+90==x2)
            {
                app.clear();
                app.draw(sprite2);
            }
        //UN TOQUE SIGNIFICA UN TOQUE
        funcionizquierda(sprite,x,y,0,0);
        funcionderecha(sprite,x,y,0,0);
        funcionarriba(sprite,x,y,0,0);
        funcionabajo(sprite,x,y,0,0);
        //Charizard2
        funcionizquierda2(sprite,x2,y2,110,196);
        funcionderecha2(sprite,x2,y2,110,196);
        funcionarriba2(sprite,x2,y2,110,196);
        funcionabajo2(sprite,x2,y2,110,196);
        }
        /*//No siguifica el toque de una tecla
        funcionizquierda(sprite,x,y,0,0);
        funcionderecha(sprite,x,y,0,0);
        funcionarriba(sprite,x,y,0,0);
        funcionabajo(sprite,x,y,0,0);
        //Charizard2
        funcionizquierda2(sprite,x2,y2,110,196);
        funcionderecha2(sprite,x2,y2,110,196);
        funcionarriba2(sprite,x2,y2,110,196);
        funcionabajo2(sprite,x2,y2,110,196);
        */
        //Muestra todo lo modificado en app

        app.display();

    }

    return EXIT_SUCCESS;
}

void funcionizquierda(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday)
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        //Se toma una seccion de la imagen FULL.png el primer 0 es la posicion x donde inicia mi primer charizard, el segundo 0 es la posicion donde inicia mi primer charizard.
        //90*90 es el area de mi rectangulo
        sprite.setTextureRect(sf::IntRect(coordenadax, coordenaday, tam, tam));
        //Se asigna la posicion del charizard, la posicion donde iniciara mi dibujo tanto en x como y (pixeles)
        sprite.setPosition(Vector2f(x, y));
        //Dibuja mi sprite (Charizard)
        app.draw(sprite);
        if(x>=0 and x<=(dimensionx-tam))
        {
            x=x-1;
        }
        else if(x<0)
        {
            x=0;
        }else if(x>dimensionx-tam){
            x=dimensionx-tam;
        }

    }
}
void funcionderecha(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday)
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        //Se toma una seccion de la imagen FULL.png el primer 0 es la posicion x donde inicia mi primer charizard, el segundo 0 es la posicion donde inicia mi primer charizard.
        //90*90 es el area de mi rectangulo
        sprite.setTextureRect(sf::IntRect(coordenadax, coordenaday, tam, tam));
        //Se asigna la posicion del charizard, la posicion donde iniciara mi dibujo tanto en x como y (pixeles)
        sprite.setPosition(Vector2f(x, y));
        //Dibuja mi sprite (Charizard)
        app.draw(sprite);
        if(x>=0 and x<=(dimensionx-tam))
        {
            x=x+1;
        }
        else
        {
            x=x-1;
        }

    }
}
void funcionarriba(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday)
{
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        //Se toma una seccion de la imagen FULL.png el primer 0 es la posicion x donde inicia mi primer charizard, el segundo 0 es la posicion donde inicia mi primer charizard.
        //90*90 es el area de mi rectangulo
        sprite.setTextureRect(sf::IntRect(coordenadax, coordenaday, tam, tam));
        //Se asigna la posicion del charizard, la posicion donde iniciara mi dibujo tanto en x como y (pixeles)
        sprite.setPosition(Vector2f(x, y));
        //Dibuja mi sprite (Charizard)
        app.draw(sprite);
        if(y>=0 and y<=(dimensiony-tam))
        {
            y=y-1;
        }
        else
        {
            y=y+1;
        }

    }
}
void funcionabajo(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday)
{
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        //Se toma una seccion de la imagen FULL.png el primer 0 es la posicion x donde inicia mi primer charizard, el segundo 0 es la posicion donde inicia mi primer charizard.
        //90*90 es el area de mi rectangulo
        sprite.setTextureRect(sf::IntRect(coordenadax, coordenaday, tam, tam));
        //Se asigna la posicion del charizard, la posicion donde iniciara mi dibujo tanto en x como y (pixeles)
        sprite.setPosition(Vector2f(x, y));
        //Dibuja mi sprite (Charizard)
        app.draw(sprite);
        if(y>=0 and y<=(dimensiony-tam))
        {
            y=y+1;
        }
        else
        {
            y=y-1;
        }

    }
}
//////FUNCIONES PARA CHARIZARD2

void funcionizquierda2(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday)
{
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        //Se toma una seccion de la imagen FULL.png el primer 0 es la posicion x donde inicia mi primer charizard, el segundo 0 es la posicion donde inicia mi primer charizard.
        //90*90 es el area de mi rectangulo
        sprite.setTextureRect(sf::IntRect(coordenadax, coordenaday, tam, tam));
        //Se asigna la posicion del charizard, la posicion donde iniciara mi dibujo tanto en x como y (pixeles)
        sprite.setPosition(Vector2f(x, y));
        //Dibuja mi sprite (Charizard)
        app.draw(sprite);
        if(x>=0 and x<=(dimensionx-tam))
        {
            x=x-1;
        }
        else
        {
            x=x+1;
        }

    }
}
void funcionderecha2(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday)
{
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        //Se toma una seccion de la imagen FULL.png el primer 0 es la posicion x donde inicia mi primer charizard, el segundo 0 es la posicion donde inicia mi primer charizard.
        //90*90 es el area de mi rectangulo
        sprite.setTextureRect(sf::IntRect(coordenadax, coordenaday, tam, tam));
        //Se asigna la posicion del charizard, la posicion donde iniciara mi dibujo tanto en x como y (pixeles)
        sprite.setPosition(Vector2f(x, y));
        //Dibuja mi sprite (Charizard)
        app.draw(sprite);
        if(x>=0 and x<=(dimensionx-tam))
        {
            x=x+1;
        }
        else
        {
            x=x-1;
        }

    }
}
void funcionarriba2(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday)
{
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        //Se toma una seccion de la imagen FULL.png el primer 0 es la posicion x donde inicia mi primer charizard, el segundo 0 es la posicion donde inicia mi primer charizard.
        //90*90 es el area de mi rectangulo
        sprite.setTextureRect(sf::IntRect(coordenadax, coordenaday, tam, tam));
        //Se asigna la posicion del charizard, la posicion donde iniciara mi dibujo tanto en x como y (pixeles)
        sprite.setPosition(Vector2f(x, y));
        //Dibuja mi sprite (Charizard)
        app.draw(sprite);
        if(y>=0 and y<=(dimensiony-tam))
        {
            y=y-1;
        }
        else
        {
            y=y+1;
        }

    }
}
void funcionabajo2(Sprite sprite,int &x,int &y,int coordenadax,int coordenaday)
{
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        //Se toma una seccion de la imagen FULL.png el primer 0 es la posicion x donde inicia mi primer charizard, el segundo 0 es la posicion donde inicia mi primer charizard.
        //90*90 es el area de mi rectangulo
        sprite.setTextureRect(sf::IntRect(coordenadax, coordenaday, tam, tam));
        //Se asigna la posicion del charizard, la posicion donde iniciara mi dibujo tanto en x como y (pixeles)
        sprite.setPosition(Vector2f(x, y));
        //Dibuja mi sprite (Charizard)
        app.draw(sprite);
        if(y>=0 and y<=(dimensiony-tam))
        {
            y=y+1;
        }
        else
        {
            y=y-1;
        }

    }
}
