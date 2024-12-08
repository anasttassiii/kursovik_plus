#include "Game.h"

Game::Game() : window(VideoMode(size* N, size* M), "Snake Game!"), snake(4), fruit(10, 10), isGameOver(false) {
    srand(static_cast<unsigned>(time(0)));
    timer = 0;
    delay = 0.1f;

    // загрузка шрифта
    if (!font.loadFromFile("font.ttf")) {

    }

    
    score = 0; 
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(10, 10); // позиция для score

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



void Game::update() {
    snake.move(); // Move the snake

    // Check if snake goes out of bounds
    if (snake.checkCollisionBounds(window.getSize().x, window.getSize().y)) {
        isGameOver = true; // Activate Game Over
    }

    // Check for fruit consumption
    if (snake.getBody().front().getPosition() == Vector2f(fruit.x * size, fruit.y * size)) {
        snake.grow(); // Increase snake length
        fruit.respawn(N, M); // Respawn fruit
        score++; // Increase score
        updateScoreText(); // Update score text
    }

    snake.checkSelfCollision(); // Check for self-collision

    if (snake.getLength() < 1) {
        isGameOver = true; // If snake length is less than 1, game over
    }
}


void Game::updateScoreText() {
    std::ostringstream scoreStream; // Create a stream for score
    scoreStream << "Score: " << score; // Format score text
    scoreText.setString(scoreStream.str()); // Set score text
}

void Game::draw() {
    window.clear();
    if (isGameOver) {
        drawGameOver(); // Draw Game Over screen
    }
    else {
        // Draw fruit
        CircleShape fruitShape(8);
        fruitShape.setFillColor(Color::Red);
        fruitShape.setPosition(fruit.x * size, fruit.y * size);
        window.draw(fruitShape);

        // Draw snake
        for (const auto& segment : snake.getBody()) {
            window.draw(segment);
        }

        // Draw score text
        window.draw(scoreText);
    }
    window.display();
}

void Game::drawGameOver() {
    // Draw Game Over text
    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50); // Large font for Game Over
    gameOverText.setFillColor(Color::Red);
    gameOverText.setString("Game Over");

    // Position the text
    gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2,
        window.getSize().y / 2 - gameOverText.getGlobalBounds().height / 2 - 30);
    window.draw(gameOverText);

    // Draw score display text
    Text scoreDisplayText;
    scoreDisplayText.setFont(font);
    scoreDisplayText.setCharacterSize(30); // Smaller font for score
    scoreDisplayText.setFillColor(Color::White);
    std::ostringstream scoreStream;
    scoreStream << "Score: " << score; // Format score text
    scoreDisplayText.setString(scoreStream.str());
    scoreDisplayText.setPosition(window.getSize().x / 2 - scoreDisplayText.getGlobalBounds().width / 2,
        window.getSize().y / 2 + 10);
    window.draw(scoreDisplayText);

    // Instructions for restarting
    Text instructionsText;
    instructionsText.setFont(font);
    instructionsText.setCharacterSize(20); // Even smaller font for instructions
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
    fruit.respawn(N, M); // генерация фрукта
}
