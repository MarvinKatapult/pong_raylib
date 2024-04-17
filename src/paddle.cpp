#include "paddle.hpp"
#include <raylib.h>

void Paddle::show() {
    DrawRectangle( myX, myY, myWidth, myHeight, PADDLE_COLOR );
}

void Paddle::move( int p_screen_height ) {
    int move_dir_y = 0;
    if ( IsKeyDown( myUpKey ) ) move_dir_y -= 1;
    if ( IsKeyDown( myDownKey ) ) move_dir_y += 1;

    if ( move_dir_y < 0 ) {
        if ( myY > 0 ) myY -= PADDLE_SPEED;
    }  else if ( move_dir_y > 0 ) {
        if ( myY + myHeight < p_screen_height ) myY += PADDLE_SPEED;
    }
}
