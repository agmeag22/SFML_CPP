#include <SFML/Graphics.hpp>
#include <unistd.h>

#include <stdlib.h>
using namespace std;
//using namespace sf; opcional para no tener que estar poniendo sff::
int main(){
    int x=10, y=10;
    int x2=20, y2=20;
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    sf::Texture texture2;
    //sf::IntRect(pixelX, pixelY, 90, 90);
    if (!texture.loadFromFile("FULL.png")){
        return EXIT_FAILURE;
    }
    if (!texture2.loadFromFile("boom.png")){
        return EXIT_FAILURE;
    }

    texture.setSmooth(true);
    texture2.setSmooth(true);
    sf::Sprite sprite(texture);
    sf::Sprite sprite2(texture2);
    // Start the game loop
    while (app.isOpen()){
        // Process events
        sf::Event event;
        while (app.pollEvent(event)){
            // Close window : exit
            if (event.type == sf::Event::Closed){app.close();}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
{
    sprite.setTextureRect(sf::IntRect(0, 0, 90, 90));
    sprite.setPosition(sf::Vector2f(x, y));
    app.draw(sprite);
    x=x+1;
    y=y+1;

}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    app.clear();    // Clear screen
    x=0;
    y=0;
    x2=100;
    y2=20;
    }
else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        sprite.setPosition(sf::Vector2f(x2, y2));
    sprite.setTextureRect(sf::IntRect(110, 196, 90, 90));
    app.draw(sprite); // Clear screen
    x2=x2+1;
    y2=y2+1;
    }
        // Draw the sprite
if(x==x2 or y==y2){
app.clear();
app.draw(sprite2);
}


        // Update the window
        app.display();

    }

    return EXIT_SUCCESS;
}
