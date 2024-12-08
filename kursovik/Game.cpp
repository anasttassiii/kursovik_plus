#include "Game.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Game::Game() : window(VideoMode(size* N, size* M), "Snake Game!"), snake(4), fruit(10, 10), isGameOver(false) {
    srand(static_cast<unsigned>(time(0)));
    timer = 0;
    delay = 0.1f;

    // �������� ������
    if (!font.loadFromFile("font.ttf")) {

    }

    
    score = 0; 
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(10, 10); // ������� ��� score

    fruit.respawn(N, M);
}

void Game::run() {
    while (window.isOpen()) {
        handleInput();
        if (!isGameOver) {
            if (timer > delay) {
                timer = 0; 
                update();
            }
        }
        draw();
        timer += clock.restart().asSeconds();
    }
}

void Game::handleInput() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }
    }

    if (isGameOver) {
        if (Keyboard::isKeyPressed(Keyboard::G)) {
            restartGame(); 
        }
        else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close(); 
        }
        return;
    }


    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        snake.setDirection(1);
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        snake.setDirection(2);
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        snake.setDirection(3);
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        snake.setDirection(0);
    }
}


void Game::update() {
    snake.move(); // ����������� ����

    // ��������, ������� �� ���� �� ������� ����
    if (snake.checkCollisionBounds(window.getSize().x, window.getSize().y)) {
        isGameOver = true; 
    }

    // �������� �� �������� �������
    if (snake.getBody().front().getPosition() == Vector2f(fruit.x * size, fruit.y * size)) {
        snake.grow(); // ���������� ����� ����
        fruit.respawn(N, M); // ������� �������
        score++; // ���������� �����
        updateScoreText(); // ���������� �����
    }

    snake.checkSelfCollision(); // �������� �� ����������������

    if (snake.getLength() < 1) {
        isGameOver = true; // ���� ����� ���� ������ 1, ���� ��������
    }
}


void Game::updateScoreText() {
    std::ostringstream scoreStream; 
    scoreStream << "Score: " << score; 
    scoreText.setString(scoreStream.str()); 
}

void Game::draw() {
    window.clear();
    if (isGameOver) {
        drawGameOver(); // ��������� ������ Game Over
    }
    else {
        // ��������� ������
        CircleShape fruitShape(8);
        fruitShape.setFillColor(Color::Red);
        fruitShape.setPosition(fruit.x * size, fruit.y * size);
        window.draw(fruitShape);

        // ��������� ������
        for (const auto& segment : snake.getBody()) {
            window.draw(segment);
        }

        // ��������� �����
        window.draw(scoreText);
    }
    window.display();
}

void Game::drawGameOver() {
    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50); 
    gameOverText.setFillColor(Color::Red);
    gameOverText.setString("Game Over");

    // ������������ ������
    gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2,
        window.getSize().y / 2 - gameOverText.getGlobalBounds().height / 2 - 30);
    window.draw(gameOverText);

    // ��������� �����
    Text scoreDisplayText;
    scoreDisplayText.setFont(font);
    scoreDisplayText.setCharacterSize(30); 
    scoreDisplayText.setFillColor(Color::White);
    std::ostringstream scoreStream;
    scoreStream << "Score: " << score; 
    scoreDisplayText.setString(scoreStream.str());
    scoreDisplayText.setPosition(window.getSize().x / 2 - scoreDisplayText.getGlobalBounds().width / 2,
        window.getSize().y / 2 + 10);
    window.draw(scoreDisplayText);

    // ���������� �� �����������
    Text instructionsText;
    instructionsText.setFont(font);
    instructionsText.setCharacterSize(20); 
    instructionsText.setFillColor(Color::White);
    instructionsText.setString("Press 'G' to Restart or 'Esc' to Quit");
    instructionsText.setPosition(window.getSize().x / 2 - instructionsText.getGlobalBounds().width / 2,
        window.getSize().y / 2 + 50);
    window.draw(instructionsText);
}

void Game::restartGame() {
    score = 0; 
    scoreText.setString("Score: 0"); 
    isGameOver = false; 
    snake = Snake(4); 
    snake.getBody().front().setPosition(10 * size, 10 * size);
    fruit.respawn(N, M); // ��������� ������
}
