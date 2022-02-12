#include "Body.h"
#include <memory>
#include <SFML/Graphics.hpp>

int main()
{
    int width = 1200;
    int height = 900;
    float dt = 1 / 60.0f;

    std::shared_ptr<Body> firstBody = std::make_shared<Body>(std::complex<float>{-300.0f, -160.0f}, std::complex<float>{-300.0f, -160.0f}, std::complex<float>{0.0f, 0.0f}, 100.0f, 10.0f, sf::Color::Red);
    firstBody->setK(10.0f);
    std::shared_ptr<Body> secondBody = std::make_shared<Body>(std::complex<float>{2.0f, 200.0f}, std::complex<float>{2.0f, 200.0f}, std::complex<float>{0.0f, 0.0f}, 100.0f, 10.0f, sf::Color::Green);
    secondBody->setK(10.0f);
    std::shared_ptr<Body> thirdBody = std::make_shared<Body>(std::complex<float>{260.0f, -250.0f}, std::complex<float>{260.0f, -250.0f}, std::complex<float>{0.0f, 0.0f}, 100.0f, 10.0f, sf::Color::Yellow);
    thirdBody->setK(10.0f);

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Sim");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        firstBody->draw(window, width, height);
        secondBody->draw(window, width, height);
        thirdBody->draw(window, width, height);

        firstBody->updateAccleration(secondBody);
        firstBody->updateAccleration(thirdBody);

        secondBody->updateAccleration(firstBody);
        secondBody->updateAccleration(thirdBody);

        thirdBody->updateAccleration(firstBody);
        thirdBody->updateAccleration(secondBody);
        
        firstBody->updatePosition(dt, width, height);
        secondBody->updatePosition(dt, width, height);
        thirdBody->updatePosition(dt, width, height);

        window.display();
    }

    return 0;
}