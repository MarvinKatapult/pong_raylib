#include <raylib.h>
#include "paddle.hpp"
#include "ball.hpp"

#define START_SCREEN_WIDTH  900
#define START_SCREEN_HEIGHT 450
#define BACKGROUND_COLOR    { 175, 175, 175, 0 }

#undef KEY_DOWN
#define KEY_DOWN    264
#undef KEY_UP
#define KEY_UP      265

int main() {
    
    InitWindow( START_SCREEN_WIDTH, START_SCREEN_HEIGHT, "Test Game" );
    SetTargetFPS( 60 );
    Paddle paddle1( 50, 50, 5, 75, 'W', 'S' );
    Paddle paddle2( START_SCREEN_WIDTH - 50, 50, 5, 75, KEY_UP, KEY_DOWN );
    Ball ball( START_SCREEN_WIDTH / 2, START_SCREEN_HEIGHT / 2, 10 );

    while( !WindowShouldClose() ) {

        BeginDrawing();
            ClearBackground( BACKGROUND_COLOR );

            paddle1.move( GetScreenHeight() );
            paddle1.show();
            paddle2.move( GetScreenHeight() );
            paddle2.show();
            ball.show();
            ball.move();
            ball.checkCollision( &paddle1, Ball::Left );
            ball.checkCollision( &paddle2, Ball::Right);
            ball.checkCollision( GetScreenWidth(), GetScreenHeight() );

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
