#pragma once

#define BALL_SPEED  7

class Paddle;

class Ball {

    public:
        enum Direction{
            Right = 0,
            Left
        };

        Ball( int x, int y, int radius );
        ~Ball( void ) { }

        void show( void );
        void move( void );
        void checkCollision( Paddle * paddle, Direction paddle_direction );
        void checkCollision( int screen_width, int screen_height );

    private:

        int myX, myY;
        int myRadius;
        int myVelX, myVelY;
};
