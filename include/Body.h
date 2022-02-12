#ifndef __BODY__H_
#define __BODY__H_

#include <complex>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

// This body is representation of an object on which force acting follows the inverse square law. eg - Coulombs, Gravitational, etc

class Body;
using bodyPtr = std::shared_ptr<Body>;

class Body
{
    public:
    std::complex<float> position;
    std::complex<float> lastPosition;
    std::complex<float> acc;
    float mass;
    float radius;
    sf::VertexArray trace{sf::PrimitiveType::Points, 10000};
    sf::Color color;
    float kConstant = 10.0f;
    sf::CircleShape circle;

    Body(std::complex<float> zposition, std::complex<float> zlastPosition, std::complex<float> zacc, float zmass, float zradius, sf::Color zcolor) :
            position{zposition},
            lastPosition{zlastPosition}, 
            acc{zacc},
            mass{zmass}, 
            radius{zradius},
            color{zcolor}
    {
        circle.setRadius(radius);
        circle.setFillColor(zcolor);
    }

    void setK(float zconstant)
    {
        this->kConstant = zconstant;
    }

    void updateAccleration(bodyPtr otherBody)
    {
        std::complex<float> dist = otherBody->position - position;
        float distAbs = std::abs(dist);
        acc += (kConstant * mass * otherBody->mass * dist) / (distAbs * distAbs * distAbs);
    }

    void updatePosition(float dt, int width, int height)
    {
        std::complex<float> newPosition = (2.0f * position) - lastPosition + (acc * dt * dt);
        lastPosition = position;
        position = newPosition;
        acc = std::complex<float>{0.0f, 0.0f};
    }

    void draw(sf::RenderWindow& window, int width, int height)
    {
        circle.setPosition(position.real() + 0.5f * width - radius, position.imag() + 0.5f * height - radius);
        trace.append(sf::Vertex{sf::Vector2f{position.real() +  0.5f * width, position.imag() +  0.5f * height}, color});
        window.draw(circle);
        window.draw(trace);
    }
};

std::ostream& operator << (std::ostream& os, const bodyPtr thisBody)
{
    os << "position : " << "{ " << thisBody->position.real() << "," << thisBody->position.imag() << " }\n";
    os << "last_position : " << "{ " << thisBody->lastPosition.real() << "," << thisBody->lastPosition.imag() << " }\n";
    os << "acceleration : " << "{ " << thisBody->acc.real() << "," << thisBody->acc.imag() << " }\n";
    os << "\n\n";
    return os;
}

#endif