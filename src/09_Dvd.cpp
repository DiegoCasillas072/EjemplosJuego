#include <SFML/Graphics.hpp>

int main()
{
    // crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "DVD Animation");
    window.setFramerateLimit(60);


    // cargar la textura del DVD
    sf::Texture dvdTexture;
    if (!dvdTexture.loadFromFile("assets/images/Dvd.png"))
    {
        return -1; // Manejo de error si no se puede cargar la textura
    }



    // crear un sprite para el DVD
    sf::Sprite dvdSprite(dvdTexture);
    dvdSprite.setPosition(400, 300); // Posición inicial del DVD
    dvdSprite.setScale(0.5f, 0.5f); // reducir el tamano del sprite
    dvdSprite.setOrigin(dvdTexture.getSize().x / 2, dvdTexture.getSize().y / 2); // Centrar el sprite


    // variables para la velocidad y dirección del DVD
    sf::Vector2f velocity(5.f, 3.f); // Velocidad inicial del DVD
    sf::Vector2f direction(1.f, 1.f); // Dirección inicial del DVD


    // bucle principal
    while (window.isOpen())
    {
        // manejar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close(); // Cerrar la ventana si se recibe el evento de cerrar
            }
        }

        // actualizar la posición del DVD
        dvdSprite.move(sf::Vector2f(velocity.x * direction.x, velocity.y * direction.y));

        // verificar colisiones con los bordes de la ventana
        if (dvdSprite.getPosition().x <= 0 || dvdSprite.getPosition().x >= window.getSize().x)
        {
            direction.x *= -1; // Invertir dirección horizontal
        }
        if (dvdSprite.getPosition().y <= 0 || dvdSprite.getPosition().y >= window.getSize().y)
        {
            direction.y *= -1; // Invertir dirección vertical
        }

        // limpiar la ventana
        window.clear();
        // dibujar el sprite del DVD
        window.draw(dvdSprite);
        // mostrar el contenido de la ventana
        window.display();
    }
    return 0; // Finalizar el programa


} 