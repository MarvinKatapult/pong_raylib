#pragma once

#define PADDLE_SPEED    10
#define PADDLE_COLOR    RED

class Paddle {

    public:

        Paddle( int x, int y, int w, int h, int up_key, int down_key ) : myX( x ), myY( y ), myWidth( w ), myHeight( h ), myUpKey( up_key ), myDownKey( down_key ) { }
        ~Paddle( void ) { }

        void show( void );
        void move( int screen_height );

        int width( void ) { return myWidth; }
        int height( void ) { return myHeight; }
        int x( void ) { return myX; }
        int y( void ) { return myY; }

    private:

        int myX, myY;
        int myWidth, myHeight;
        int myUpKey, myDownKey;

};
