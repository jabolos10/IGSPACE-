#pragma once
#include "Ship.h"
#include "EnemyBullet2.h"
#include "EnemyBullet2Reverse.h"

class EnemyShip2 : public Ship {
public:
    EnemyShip2(const sf::Vector2f& startPosition, const std::string& texturePath);
    void update(sf::Time dt) override; // Override update method
    void draw(sf::RenderWindow& window) const override;
    std::vector<EnemyBullet2>* hantleTheContainerOnEnemyBullets2(); //function returning container with bullets
    std::vector<EnemyBullet2Reverse>* hantleTheContainerOnEnemyBullets2Reverse(); //function returning container with bullets
    std::vector<EnemyBullet2>& getBullets();
    std::vector<EnemyBullet2Reverse>& getBulletsReverse();
    void takeDamage(); // Method to handle damage when hit
    bool isDestroyed() const; // Method to check if the enemy ship is destroyed after being hit three times
private:
    float movementDirection; // horizonal movement direction
    float movementDirection2; // vertical movement direction
    mutable std::vector<EnemyBullet2> enemybullets2; // Container to hold bullets
    mutable std::vector<EnemyBullet2Reverse> enemybullets2Reverse; // Container to hold bullets
    sf::Clock shootClock; // Timer for shooting
    sf::Time shootInterval = sf::seconds(2); // Time between shots
    void shoot(); // Method to handle shooting
    int hitCount = 0;       // Counter for the number of hits
    const int maxHits = 3;  // Maximum hits before the ship is destroyed

};

