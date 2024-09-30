#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/graphics.hpp>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong");

    Bat bat(1920 / 2-150, 1080 - 80, 300, 100);
    Ball ball(0,0,0,0,0,0);
    Font font;
    font.loadFromFile("/Users/colinwang/Downloads/KOMIKAP_.ttf");
    Text pauseText;
    Text scoreText;
    pauseText.setFont(font);
    pauseText.setString(
            "     Press Enter to continue!\n\n A moves left, D moves right!\n       Press Esc to Exit!\n      Press R to restart!");
    pauseText.setCharacterSize(75);
    pauseText.setOutlineThickness(3);
    pauseText.setFillColor(Color::White);
    pauseText.setPosition(400, 250);

    Text starttext;
    starttext.setFont(font);
    starttext.setString(
            "              PLAY\n\n    EASY   MEDIUM   HARD\n\n A moves left, D moves right!\n       Press Esc to Exit!\n      Press R to restart!");
    starttext.setCharacterSize(75);
    starttext.setOutlineThickness(3);
    starttext.setFillColor(Color::White);
    starttext.setPosition(340, 350);

    Text GameOver;
    GameOver.setFont(font);
    GameOver.setString("GameOver");
    GameOver.setCharacterSize(75);
    GameOver.setFillColor(Color::White);
    GameOver.setPosition(750, 500);

    scoreText.setFont(font);
    scoreText.setString("Score = 0");
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(0, 0);

    Text countdowntext;
    countdowntext.setFont(font);
    countdowntext.setString(" ");
    countdowntext.setCharacterSize(100);
    countdowntext.setFillColor(Color::White);
    countdowntext.setPosition(900, 540);

    Text HighScore;
    HighScore.setFont(font);
    HighScore.setString("Score = 0");
    HighScore.setCharacterSize(50);
    HighScore.setFillColor(Color::White);
    HighScore.setPosition(0, 75);

    RectangleShape pauselossBackground;
    pauselossBackground.setSize(Vector2f(1920, 1080));
    pauselossBackground.setFillColor(Color{0, 0, 0, 150});
    pauselossBackground.setOutlineThickness(0);
    pauselossBackground.setPosition(0, 0);

    RectangleShape startbackground;
    startbackground.setSize(Vector2f(1920, 1080));
    startbackground.setFillColor(Color{0, 0, 0, });
    startbackground.setPosition(0, 0);

    RectangleShape playbutton;
    playbutton.setSize(Vector2f(250, 150));
    playbutton.setFillColor(Color(0, 100, 100));
    playbutton.setPosition(775, 325);

    RectangleShape easy;
    easy.setSize(Vector2f(300, 150));
    easy.setFillColor(Color(100, 0, 0));
    easy.setPosition(415, 525);
    RectangleShape medium;
    medium.setSize(Vector2f(300, 150));
    medium.setFillColor(Color(100, 0, 0));
    medium.setPosition(740, 525);
    RectangleShape hard;
    hard.setSize(Vector2f(300, 150));
    hard.setFillColor(Color(100, 0, 0));
    hard.setPosition(1070, 525);

    Texture texturepong;
    texturepong.loadFromFile("/Users/colinwang/Downloads/pong.jpeg");
    Sprite spritePong;
    spritePong.setTexture(texturepong);
    spritePong.setScale(1,1);
    spritePong.setPosition(590, -30);

    // clock
    Clock clock;
    int difficulty = 1;
    int score = 0;
    int r = 20;
    int close = 0;
    int lives = 3;
    bool gameover = false;
    int started = 0;
    int ispaused = 0;
    int highscore = 0;
    int countdown = 4;
    int reset=0;
    srand(time(NULL));

    /*start the game*/
    int countdownclock = 399;
    bool canpause = true;
    bool canstart = true;
    bool canrestart = true;
    // game loop
    while (window.isOpen()){
        Event event;
        window.pollEvent(event);
        Time dt = clock.restart();
//        if (event.type == Event::Closed) {
//            window.close();
//        }
        if (event.type == Event::Closed) {
            if (close > 1) {
                window.close();
            }
            close++;
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        if(started==0){
            score = 0;
            lives=3;
            canpause = false;
            gameover = false;
            reset=false;
            countdown = 4;
            countdowntext.setString(" ");
            countdownclock=399;
            ball.newBall(bat.getPosition().x+(bat.getShape().getSize().x/2)-r,bat.getPosition().y-2*r-1,r,(rand()%3),(rand()%70)+30,(rand()%200)/100.0);
//            cout<<Mouse::getPosition().x<<" "<<Mouse::getPosition().y<<endl;
            if(playbutton.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(window).x),static_cast<float>(Mouse::getPosition(window).y))) {
                playbutton.setFillColor(Color(100, 100, 100));
                if (event.type ==Event::MouseButtonPressed) {
                    started = 1;
                }
            }
            else{
                playbutton.setFillColor(Color(0, 100, 100));
            }
            if (event.type ==Event::KeyPressed&&event.key.code==Keyboard::Enter) {
                started = 1;
            }
            if(easy.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(window).x),static_cast<float>(Mouse::getPosition(window).y))) {
                easy.setFillColor(Color(100, 100, 100));
                if (event.type ==Event::MouseButtonPressed) {
                    difficulty=0;
                }
            }
            else{
                easy.setFillColor(Color(100, 0, 0));
            }
            if(medium.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(window).x),static_cast<float>(Mouse::getPosition(window).y))) {
                medium.setFillColor(Color(100, 100, 100));
                if (event.type ==Event::MouseButtonPressed) {
                    difficulty=1;
                }
            }
            else{
                medium.setFillColor(Color(100, 0, 0));
            }
            if(hard.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(window).x),static_cast<float>(Mouse::getPosition(window).y))) {
                hard.setFillColor(Color(100, 100, 100));
                if (event.type ==Event::MouseButtonPressed) {
                    difficulty=2;
                }
            }
            else{
                hard.setFillColor(Color(100, 0, 0));
            }
            if(difficulty==0){
                easy.setFillColor(Color(0, 100, 0));
                 bat.newBat(1920 / 2-250, 1080 - 80, 500, 100);
            }
            if(difficulty==1){
                medium.setFillColor(Color(0, 100, 0));
                bat.newBat(1920 / 2-150, 1080 - 80, 300, 100);
            }
            if(difficulty==2){
                hard.setFillColor(Color(0, 100, 0));
                bat.newBat(1920 / 2-50, 1080 - 80, 100, 100);
            }
        }
        else {
            if (gameover) {
                if (event.type == Event::KeyReleased && event.key.code == Keyboard::Enter) {
                    started=0;
                }
            } else {
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter && canpause) {
                    ispaused++;
                    ispaused %= 2;
                    canpause = false;
                }
                else if (event.type == Event::KeyReleased && event.key.code == Keyboard::Enter && !canpause) {
                    canpause = true;
                }
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::R && canrestart) {
                    gameover = true;
                    canpause = false;
                }
                else if (event.type == Event::KeyReleased && event.key.code == Keyboard::R && !canrestart) {
                    canrestart = true;
                }
                if (ispaused % 2 == 0) {
                    if (countdown >= 0) {
                        countdownclock++;
                        countdowntext.setString(to_string(countdown));
                        if (countdown == 0) {
                            countdowntext.setString("GO!");
                        }
                        if (countdownclock >= 400) {
                            countdown--;
                            countdownclock = 0;
                        }

                    } else {
                        if(reset>0){
                            reset++;
                            if(reset>400){
                                ball.newBall(bat.getPosition().x+(bat.getShape().getSize().x/2)-r,bat.getPosition().y-2*r-1,r,(rand()%3),(rand()%70)+30,(rand()%200)/100.0);
                            }
                            if(reset>800){
                                reset=0;
                            }
                        }
                        else {
                            if (Keyboard::isKeyPressed(Keyboard::A)) {
                                bat.moveLeft();
                            } else {
                                bat.stopLeft();
                            }
                            if (Keyboard::isKeyPressed(Keyboard::D)) {
                                bat.moveRight();
                            } else {
                                bat.stopRight();
                            }
                            if (ball.getPosition().x < bat.getPosition().x + bat.getShape().getSize().x &&
                                ball.getPosition().x > bat.getPosition().x - (ball.getShape().getRadius() * 2)) {
                                if (ball.getPosition().y > bat.getPosition().y - (ball.getShape().getRadius() * 2)) {
                                    if (ball.getPosition().y < bat.getPosition().y - (ball.getShape().getRadius() * 2)+10) {
                                        ball.hitBat();
                                        score++;
                                        ball.sety(bat.getPosition().y - (ball.getShape().getRadius() * 2));
                                        highscore = max(score, highscore);
                                    }
                                }
                            }
                            if (ball.getPosition().y > 1080) {
                                lives--;
                                if (lives == 0) {
                                    gameover = true;
                                } else {
                                    reset = 1;
                                }
                            }
                            bat.update(dt);
                            ball.update(dt);
                            //cout<<ball.getPosition().x<<" "<<ball.getPosition().y<<endl;
                        }
                    }
                }
            }
        }


        window.clear();
        window.draw(bat.getShape());
        window.draw(ball.getShape());



        scoreText.setString("Score = " + to_string(score)+"\n\nLives = "+to_string(lives));
        HighScore.setString("High score = " + to_string(highscore));
        if (countdown >= 0) {
            window.draw(countdowntext);
        }
        if (ispaused % 2 == 1 && !gameover) {
            window.draw(pauselossBackground);
            window.draw(pauseText);
        }
        window.draw(scoreText);
        if (gameover) {
            window.draw(pauselossBackground);
            window.draw(GameOver);
        }
        window.draw(HighScore);
        // Show everything we just drew
        if(started==0) {
            window.draw(startbackground);
            window.draw(playbutton);
            window.draw(easy);
            window.draw(medium);
            window.draw(hard);
            window.draw(starttext);
            window.draw(spritePong);
        }
        window.display();
    }

    return 0;

}