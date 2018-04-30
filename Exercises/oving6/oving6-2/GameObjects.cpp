#include "GameObjects.hpp"

#include "cannonball.hpp"
#include <cmath>

// implement all (member) functions in this file
Target::Target(double size, double position) {
    this->size = size;
    this->position = position;
    shape = sf::RectangleShape(sf::Vector2f(this->size, this->size));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(this->position, 0);
}

void Target::update() {}

void Target::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}

Cannonball::Cannonball(double angle, double initial_velocity, double startPosX, double startPosY) {
    getVelocityVector(angle, initial_velocity, &startVelX, &startVelY);
    this->startPosX = startPosX;
    this->startPosY = startPosY;
    this->shape = sf::CircleShape(this->size);
    this->shape.setFillColor(sf::Color::Blue);
    this->shape.setOrigin(this->size, this->size);
}

double Cannonball::getPosX() const {
    return posX(this->startPosX, this->startVelX, getAirTime());
}

double Cannonball::getPosY() const {
    return posY(this->startPosY, this->startVelY, getAirTime());
}

void Cannonball::update() {
    this->shape.setPosition(getPosX(), getPosY());
}

void Cannonball::draw(sf::RenderWindow& window) {
    window.draw(this->shape);
}

bool Cannonball::hasLanded() const {
    return getPosY() + size < 0;
}

double Cannonball::getAirTime() const {
    return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}

Cannon::Cannon() {
    this->shape = sf::RectangleShape(sf::Vector2f(this->width, this->length));
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setPosition(0, 0);
    this->shape.setOrigin(this->width/2, 0);
}

void Cannon::update() {
    this->shape.setRotation(this->theta - 90);
}

void Cannon::draw(sf::RenderWindow& window) {
    window.draw(this->shape);
}

double Cannon::getTipX() const {
    return length*cos(degToRad(theta));
}

double Cannon::getTipY() const {
    return length*sin(degToRad(theta));
}

Cannonball Cannon::shoot() {
    Cannonball cannonball(this->theta, this->velocity, this->getTipX(), this->getTipY());
    return cannonball;
}

void Cannon::incrementAngle(double dtheta) {
    this->theta += dtheta;
}
void Cannon::decrementAngle(double dtheta) {
    this->theta -= dtheta;
}

void Cannon::incrementVelocity(double dvel) {
    this->velocity += dvel;
}
void Cannon::decrementVelocity(double dvel) {
    this->velocity -= dvel;
}
