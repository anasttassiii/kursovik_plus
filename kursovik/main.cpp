#include "Game.h"
#include <iostream>
#include "snake.h"
#include <vector>
#include <windows.h>
#include <conio.h>
#include <sstream> 
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;
bool start = true;

void showWelcomeScreen(sf::RenderWindow& window, sf::Font& font) {

    Image snakeimage;
    snakeimage.loadFromFile("snake.png");

    Texture snakeTexture;
    snakeTexture.loadFromImage(snakeimage);

    Sprite snakeSprite;
    snakeSprite.setTexture(snakeTexture);
    snakeSprite.setPosition(50, 25);
    
    float scaleFactor = 0.3f; 
    snakeSprite.setScale(scaleFactor, scaleFactor); 

    // ���������� ������ ��������������� ��� ������� �����������
    snakeSprite.setPosition(window.getSize().x / 2 - snakeSprite.getGlobalBounds().width / 2,
        window.getSize().y / 2 - snakeSprite.getGlobalBounds().height / 2 - 100 -80); 





  
    // �������� ����� ��� ������ �����������
    sf::Text welcomeText;
    welcomeText.setFont(font);
    welcomeText.setCharacterSize(50);
    welcomeText.setFillColor(sf::Color::White);
    welcomeText.setString("Welcome to Snake Game!");

    // ���������� ��������������� ���������
    welcomeText.setPosition(window.getSize().x / 2 - welcomeText.getGlobalBounds().width / 2,
        window.getSize().y / 2 - welcomeText.getGlobalBounds().height / 2 - 30);

    // �������� ����� ��� ��������
    sf::Text descriptionText;
    descriptionText.setFont(font);
    descriptionText.setCharacterSize(30);
    descriptionText.setFillColor(sf::Color::White);
    descriptionText.setString("Use arrow keys to control the snake.");

    // ������������ ��������
    descriptionText.setPosition(window.getSize().x / 2 - descriptionText.getGlobalBounds().width / 2,
        window.getSize().y / 2 + 30);

    // �������� ����� ��� ����������
    sf::Text instructionsText;
    instructionsText.setFont(font);
    instructionsText.setCharacterSize(20);
    instructionsText.setFillColor(sf::Color::White);
    instructionsText.setString("Press any key to start the game, Esc to exit.");

    // ������������ ����������
    instructionsText.setPosition(window.getSize().x / 2 - instructionsText.getGlobalBounds().width / 2,
        window.getSize().y / 2 + 100);

    // �������� ���� ��� ������ �����������
    while (true) {
        window.clear();
        window.draw(snakeSprite);
        window.draw(welcomeText);
        window.draw(descriptionText);
        window.draw(instructionsText);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return; // ����� �� �������
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    start - false;
                    window.close();
                }
                else {
                    return; // ������ ���� ��� ������� ����� ������ �������
                }
            }
        }
    }
}

int main() {
    if (start != false) {
        sf::RenderWindow window(sf::VideoMode(1120, 640), "Snake Game!"); 
        sf::Font font;

        // ��������� �����
        if (!font.loadFromFile("font.ttf")) {
            std::cerr << "Error loading font" << std::endl;
            return -1; // ����� ��� ���� �������� ������
        }

        // �������� ����� �����������
        showWelcomeScreen(window, font);

        // �������� ����
        Game game;

        // ������ ����
        game.run();

    }
    
    return 0;
}