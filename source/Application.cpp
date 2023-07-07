#include "../include/Application.h"

using namespace controllers;

Application::Application()
    : mWindow(sf::VideoMode(720, 672), "Battle City"), gameOver(false), gameStarted(false),
    msgStart(90, 330, "Press \'Enter\' to start"), msgOver(250, 300, "Game over"),
    msgLost(260, 350, "You lost"), msgWon(265, 350, "You won"), frags(0) {

    sf::Clock clock;

    this->packOfEnemies = new Enemy[4]{ Enemy(52,31), Enemy(147,391), Enemy(532,391), Enemy(628,31) };

    while (this->mWindow.isOpen()) {
        sf::Int64 time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        process_events();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            this->gameStarted = true;

        if (this->gameStarted && !this->gameOver)
            update(time);
        render();
    }
}

void Application::process_events() {
    sf::Event event;
    while (this->mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->mWindow.close();
                break;
        }
    }
}

void Application::update(const sf::Int64 &time) {
    for (int i(0); i < 4; ++i)
        if (!packOfEnemies[i].getlife())
            ++this->frags;
        else {
            this->frags = 0;
            break;
        }

    if (this->frags == 4)
        this->gameOver = true;

    if (!this->mPlayer.getlife())
        this->gameOver = true;

    bool collision;

    for (int i(0); i < 4; ++i) {
        collision = this->mPlayer.getSprite()->getGlobalBounds().intersects(packOfEnemies[i].getSprite()->getGlobalBounds());
        if (collision)
            break;
    }

    if (this->mPlayer.getlife())
        this->mPlayer.update(time, map, collision);

    for (int i(0); i < 4; ++i) {
        if (packOfEnemies[i].getlife()) {
            packOfEnemies[i].update(time, map, collision);

            if (packOfEnemies[i].getbullet()->getSprite().getGlobalBounds().intersects(this->mPlayer.getSprite()->getGlobalBounds())
                && packOfEnemies[i].getbullet()->getpresent()) {
                this->mPlayer.collapse();
                packOfEnemies[i].getbullet()->setpresent(false);
            }

            if (packOfEnemies[i].getbullet()->getSprite().getGlobalBounds().intersects(this->mBase.getSprite()->getGlobalBounds())
                && packOfEnemies[i].getbullet()->getpresent()) {
                this->mBase.setlife(false);
                this->gameOver = true;
            }
            if (this->mPlayer.getbullet()->getSprite().getGlobalBounds().intersects(packOfEnemies[i].getSprite()->getGlobalBounds())
                && this->mPlayer.getbullet()->getpresent()) {
                packOfEnemies[i].collapse();
                this->mPlayer.getbullet()->setpresent(false);
            }
        }
    }

    if (this->mPlayer.getbullet()->getSprite().getGlobalBounds().intersects(this->mBase.getSprite()->getGlobalBounds())
        && this->mPlayer.getbullet()->getpresent()) {
        this->mBase.setlife(false);
        this->gameOver = true;
    }
}

void Application::render() {
    this->mWindow.clear();
    this->map.draw(this->mWindow);
    if (this->mPlayer.getlife())
        this->mWindow.draw(*(this->mPlayer.getSprite()));

    if (this->mPlayer.getbullet()->getpresent()) mWindow.draw((mPlayer.getbullet()->getSprite()));

    for (int i(0); i < 4; ++i) {
        if (packOfEnemies[i].getbullet()->getpresent())
            mWindow.draw(packOfEnemies[i].getbullet()->getSprite());

        if (packOfEnemies[i].getlife())
            mWindow.draw(*(packOfEnemies[i].getSprite()));
    }

    if (this->mBase.getlife())
        this->mWindow.draw(*(this->mBase.getSprite()));

    if (!gameStarted)
        this->msgStart.print(mWindow);

    if (this->gameOver) {
        this->msgOver.print(mWindow);
        if (!this->mBase.getlife() || !this->mPlayer.getlife())

            this->msgLost.print(mWindow);
        else
            this->msgWon.print(mWindow);
    }

    this->mWindow.display();
}
