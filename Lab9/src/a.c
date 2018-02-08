#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

// OUTPUT: LED
#define R_LED   8
#define Y_LED   9
#define G_LED   7
#define B_LED   21

// INPUT: Push Buttons
#define PB1             27
#define PB2             0
#define PB3             1
#define PB4             24
#define PB5             28

void allLightsOn( int milli );
void blinkLight( int light, int milli, int n );
void getButtonPress( void );
void convertToBinary( double value );

int main( int arc, char **argv )
{
        short on = 1;
        int state = 0;
        double count;

        wiringPiSetup();

        pinMode( R_LED, OUTPUT );
        pinMode( Y_LED, OUTPUT );
        pinMode( G_LED, OUTPUT );
        pinMode( B_LED, OUTPUT );

        pinMode( PB1, INPUT );
        pinMode( PB2, INPUT );
        pinMode( PB3, INPUT );
        pinMode( PB4, INPUT );
        pinMode( PB5, INPUT );

        pullUpDnControl( PB1, PUD_DOWN );
        pullUpDnControl( PB2, PUD_DOWN );
        pullUpDnControl( PB3, PUD_DOWN );
        pullUpDnControl( PB4, PUD_DOWN );
        pullUpDnControl( PB5, PUD_DOWN );

        // State Machine
        while( on )
        {
                switch( state ) {
                        case 0:         // Signal Start
                                count = 0;
                                allLightsOn( 1000 );
                                state = 1;
                                break;   
                        case 1:
                                if( count > 15 ) {
                                       state = 0;
                                }
                                getButtonPress();
                                count += 1.0;
                                convertToBinary( count );                                                                                       
                                break;
                        case 2:
                                on = 0;
                                break;
                        default:        // Invalid input
                                on = 0;
                                break;
                } // END SWITCH : State Machine
        } // END WHILE : Main Program Loop

        return 0;
}

void allLightsOn( int milli )
{
        digitalWrite( R_LED, HIGH ); 
        digitalWrite( Y_LED, HIGH );
        digitalWrite( G_LED, HIGH );
        digitalWrite( B_LED, HIGH );
        delayMicroseconds( milli*1000 );
        digitalWrite( R_LED, LOW );
        digitalWrite( Y_LED, LOW );
        digitalWrite( G_LED, LOW );
        digitalWrite( B_LED, LOW );
} // END FUNCTION allLightsOn

void getButtonPress( void ) {
        while( (digitalRead(PB1) || digitalRead(PB2) || digitalRead(PB3) || digitalRead(PB4) || digitalRead(PB5)) != 1 )
        {
                delayMicroseconds( 1000 );
        }
}

void convertToBinary( double value )
{
        double remainder = 0;

        if( (int)value % 2 == 1 ) { remainder = 1; }

        value /= 2.0;

        if( remainder == 1 ){
                digitalWrite( R_LED, HIGH );
        } else {
                digitalWrite( R_LED, LOW );
        }

        if( (int)value % 2 == 1 ) { remainder = 1; }
        value /= 2.0;

        if( remainder == 1 ) {
                digitalWrite( Y_LED, HIGH );
        } else {
                digitalWrite( Y_LED, LOW );
        }

        if( (int)value % 2 == 1 ) { remainder = 1; }
        value /= 2.0;

        if( remainder == 1 ) {
                digitalWrite( G_LED, HIGH );
        } else {
                digitalWrite( G_LED, LOW );
        }

        if( (int)value % 2 == 1 ) { remainder = 1; }
        value /= 2.0;

        if( remainder == 1 ) {
                digitalWrite( B_LED, HIGH );
        } else {
                digitalWrite( B_LED, LOW );
        }

}

