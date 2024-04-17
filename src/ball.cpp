#include "ball.hpp"

#include <raylib.h>
#include "paddle.hpp"

Ball::Ball( int x, int y, int radius ) : myX( x ), myY( y ), myRadius( radius ) { 
    myVelX = BALL_SPEED;
    myVelY = BALL_SPEED;
}

void Ball::show() {
    DrawCircle( myX, myY, myRadius, RED );
}

void Ball::move() {
    myX += myVelX; 
    myY += myVelY; 
}

void Ball::checkCollision( Paddle * paddle, Ball::Direction paddle_direction ) {
    if ( !paddle ) return;

    bool between_paddle_edges = myY + myRadius > paddle->y() && myY - myRadius < paddle->y() + paddle->height();
    if ( ( ( paddle_direction == Right && myX + myRadius > paddle->x() ) || ( paddle_direction == Left && myX - myRadius < paddle->x() ) ) && between_paddle_edges ) {
        myVelX *= -1;
    } 
}

void Ball::checkCollision( int screen_width, int screen_height ) {
    if ( myX - myRadius < 0 || myX + myRadius > screen_width ) {
        myVelX *= -1;
    }
    if ( myY - myRadius < 0 || myY + myRadius > screen_height ) {
        myVelY *= -1;
    }
}
