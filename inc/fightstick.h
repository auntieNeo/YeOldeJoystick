#ifndef _FIGHTSTICK_H_
#define _FIGHTSTICK_H_

/**********************************************************
 * fightstick.h
 * John Burkert (johnburkert@gmail.com)
 *
 * Adapted from snes.h by
 * "Jonathan Glines" <auntieNeo@gmail.com>
 *
 * The following websites were used as references for this project.
 * A very big THANK YOU to the authors for sharing their knowledge!!!
 *
 *   http://www.artlum.com/gameduino/nes.html
 *   http://pinouts.ru/Game/snescontroller_pinout.shtml
 *   http://www.slashdev.ca/2010/05/25/ps3-gamepad-with-home-button/
 *   http://www.pjrc.com/teensy/index.html
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**********************************************************
 * fightstick button masks and defines
 */

uint8_t BUTTON = 0;
uint8_t STICK = 0;
uint8_t EXTRA = 0;

#define BUTTON_CIRCLE   (1 << 0)
#define BUTTON_CROSS    (1 << 1)
#define BUTTON_TRIANGLE (1 << 2)
#define BUTTON_SQUARE   (1 << 3)
#define BUTTON_R1       (1 << 4)
#define BUTTON_R2       (1 << 5)
#define BUTTON_L1       (1 << 6)
#define BUTTON_L2       (1 << 7)

#define STICK_UP         (1 << 0)
#define STICK_DOWN       (1 << 1)
#define STICK_LEFT       (1 << 4)
#define STICK_RIGHT      (1 << 5)

#define EXTRA_START    (1 << 0)
#define EXTRA_SELECT   (1 << 1)
#define EXTRA_PS      (1 << 2)
#define EXTRA_REBOOT  (1 << 3)

/**********************************************************
 * gamepad button defines
 */

#define GAMEPAD_CIRCLE_ON	    (BUTTON & BUTTON_CIRCLE)
#define GAMEPAD_CROSS_ON	    (BUTTON & BUTTON_CROSS)
#define GAMEPAD_TRIANGLE_ON	  (BUTTON & BUTTON_TRIANGLE)
#define GAMEPAD_SQUARE_ON	    (BUTTON & BUTTON_SQUARE)

#define GAMEPAD_R1_ON	        (BUTTON & BUTTON_R1)
#define GAMEPAD_R2_ON	        (BUTTON & BUTTON_R2)
#define GAMEPAD_L1_ON	        (BUTTON & BUTTON_L1)
#define GAMEPAD_L2_ON	        (BUTTON & BUTTON_L2)

#define GAMEPAD_UP_ON	        (STICK & STICK_UP)
#define GAMEPAD_DOWN_ON	      (STICK & STICK_DOWN)
#define GAMEPAD_LEFT_ON       (STICK & STICK_LEFT)
#define GAMEPAD_RIGHT_ON	    (STICK & STICK_RIGHT)

#define GAMEPAD_START_ON		  (EXTRA & EXTRA_START)
#define GAMEPAD_SELECT_ON	    (EXTRA & EXTRA_SELECT)
#define GAMEPAD_PS_ON	        (EXTRA & EXTRA_PS)
#define GAMEPAD_REBOOT_ON	    (EXTRA & EXTRA_REBOOT)

/**********************************************************
 * fightpad pins
 *
 *    PS                                     SELECT  START
 *
 *
 *                                 ___     ___     ___
 *          UP             ___    /   \   /   \   /   \
 *          ___           /   \  |  ^  | | R 1 | | L 1 |
 *         /   \         | [_] |  \___/   \___/   \___/
 *  LEFT  |     | RIGHT   \___/    ___     ___     ___
 *         \___/           ___    /   \   /   \   /   \
 *                        /   \  |  O  | | R 2 | | L 2 |
 *         DOWN          |  X  |  \___/   \___/   \___/
 *                        \___/
 *
 *
 *
 * Circle Button     ---> PB0
 * Cross Button      ---> PB1
 * Triangle Button   ---> PB2
 * Square Button     ---> PB3
 *
 * R1 Button  ---> PB4
 * R2 Button  ---> PB5
 * L1 Button  ---> PB6
 * L2 Button  ---> PB7
 *
 * Stick Up (orange)    --->  PF0
 * Stick Down (red)     --->  PF1
 * Stick Left (yellow)  --->  PF4
 * Stick Right (green)  --->  PF5
 *
 * Start Button   ---> PD0
 * Select Button  ---> PD1
 * PS Button      ---> PD2
 *
 */


/**********************************************************
 * initialize pins
 */ 

void gamepad_init(void) {
    // set input with pull-up resistors
#define PULLUP_INPUT(port, pin)  DDR ## port &= ~pin;  PORT ## port |= pin;
    PULLUP_INPUT(B, BUTTON_CIRCLE);
    PULLUP_INPUT(B, BUTTON_CROSS);
    PULLUP_INPUT(B, BUTTON_TRIANGLE);
    PULLUP_INPUT(B, BUTTON_SQUARE);
    PULLUP_INPUT(B, BUTTON_R1);
    PULLUP_INPUT(B, BUTTON_R2);
    PULLUP_INPUT(B, BUTTON_L1);
    PULLUP_INPUT(B, BUTTON_L2);
    PULLUP_INPUT(F, STICK_UP);
    PULLUP_INPUT(F, STICK_DOWN);
    PULLUP_INPUT(F, STICK_LEFT);
    PULLUP_INPUT(F, STICK_RIGHT);
    PULLUP_INPUT(D, EXTRA_START);
    PULLUP_INPUT(D, EXTRA_SELECT);
    PULLUP_INPUT(D, EXTRA_PS);
}

/**********************************************************
 * read pins and set buttons masks
 */ 

void gamepad_read(void) {
    // read button inputs
    BUTTON = PINB & BUTTON_CIRCLE;
    BUTTON |= PINB & BUTTON_CROSS;
    BUTTON |= PINB & BUTTON_TRIANGLE;
    BUTTON |= PINB & BUTTON_SQUARE;
    BUTTON |= PINB & BUTTON_R1;
    BUTTON |= PINB & BUTTON_R2;
    BUTTON |= PINB & BUTTON_L1;
    BUTTON |= PINB & BUTTON_L2;

    // read stick inputs
    STICK = PINF & STICK_UP;
    STICK |= PINF & STICK_DOWN;
    STICK |= PINF & STICK_LEFT;
    STICK |= PINF & STICK_RIGHT;
    
    // read extra inputs
    EXTRA = PIND & EXTRA_START;
    EXTRA |= PIND & EXTRA_SELECT;
    EXTRA |= PIND & EXTRA_PS;

    // TODO: define virtual buttons for reboot

    /*
    // handle virtual buttons
    // ps       : select + start
    // reboot   : select + start + l1 + r1
    // l2       : select + l1
    // r2       : select + r1
    VIRTUAL = 0;
    if (GAMEPAD_SELECT_ON) {
        if (GAMEPAD_START_ON) {
            if (GAMEPAD_L1_ON && GAMEPAD_R1_ON) {
                // reboot
                VIRTUAL = VIRTUAL_REBOOT;
                // eat buttons
                BUTTON &= ~BUTTON_L1;
                BUTTON &= ~BUTTON_R1;
            } else {
                // ps
                VIRTUAL = VIRTUAL_PS;
            }

            // eat buttons
            BUTTON &= ~BUTTON_START;
            BUTTON &= ~BUTTON_SELECT;
        } else {
            if (GAMEPAD_L1_ON) {
                // l2
                VIRTUAL |= VIRTUAL_L2;
                // eat buttons
                BUTTON &= ~BUTTON_L1;
                BUTTON &= ~BUTTON_SELECT;
            }
            if (GAMEPAD_R1_ON) {
                // r2
                VIRTUAL |= VIRTUAL_R2;
                // eat buttons
                BUTTON &= ~BUTTON_R1;
                BUTTON &= ~BUTTON_SELECT;
            }
        }
    }
    */
}

#endif
