#pragma once
#include "Ship.h"
#include "EnemyBullet.h"

class EnemyShip : public Ship {
public:
    EnemyShip(const sf::Vector2f& startPosition, const std::string& texturePath);
    void update(sf::Time dt) override; // Override update method
    void draw(sf::RenderWindow& window) const override;
    std::vector<EnemyBullet>* hantleTheContainerOnEnemyBullets(); // function returning container with bullets
    std::vector<EnemyBullet>& getBullets();

private:
    float movementDirection; // horizontal movement direction
    float movementDirectionY; // vertical movement direction
    mutable std::vector<EnemyBullet> enemybullets; // Container to hold bullets
    sf::Clock shootClock; // Timer for shooting
    sf::Time shootInterval = sf::seconds(0.7); // Time between shots
    void shoot(); // Method to handle shooting
};
