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

uint8_t PORT_A_INPUT = 0;
uint8_t PORT_B_INPUT = 0;
uint8_t PORT_C_INPUT = 0;
uint8_t PORT_D_INPUT = 0;
uint8_t PORT_E_INPUT = 0;
uint8_t PORT_F_INPUT = 0;

#define _port(input)  PORT_ ## input
#define _pin(input)  PIN_ ## input
#define _input(port)  PORT_ ## port ## _INPUT

#define TEENSY_2_0_PLUS_PLUS


#ifdef TEENSY_1_0
#define PORT_CIRCLE C
#define PIN_CIRCLE 2

#define PORT_CROSS D
#define PIN_CROSS 0

#define PORT_TRIANGLE D
#define PIN_TRIANGLE 1

#define PORT_SQUARE D
#define PIN_SQUARE 2

#define PORT_R1 B
#define PIN_R1 3

#define PORT_R2 B
#define PIN_R2 4

#define PORT_L1 B
#define PIN_L1 5

#define PORT_L2 D
#define PIN_L2 3

#define PORT_UP C
#define PIN_UP 4

#define PORT_DOWN C
#define PIN_DOWN 5

#define PORT_LEFT C
#define PIN_LEFT 6

#define PORT_RIGHT C
#define PIN_RIGHT 7

#define PORT_START D
#define PIN_START 4

#define PORT_SELECT D
#define PIN_SELECT 5

#define PORT_PS D
#define PIN_PS 7

#define LED_CONFIG	(DDRD |= (1<<6))
#define LED_ON	(PORTD &= ~(1<<6))
#define LED_OFF	(PORTD |= (1<<6))
#endif

#ifdef TEENSY_2_0_PLUS_PLUS
#define PORT_CIRCLE B
#define PIN_CIRCLE 7

#define PORT_CROSS D
#define PIN_CROSS 0

#define PORT_TRIANGLE D
#define PIN_TRIANGLE 1

#define PORT_SQUARE D
#define PIN_SQUARE 2

#define PORT_R1 E
#define PIN_R1 6

#define PORT_R2 E
#define PIN_R2 7

#define PORT_L1 B
#define PIN_L1 0

#define PORT_L2 D
#define PIN_L2 3

#define PORT_UP B
#define PIN_UP 6

#define PORT_DOWN B
#define PIN_DOWN 5

#define PORT_LEFT B
#define PIN_LEFT 4

#define PORT_RIGHT B
#define PIN_RIGHT 3

#define PORT_START D
#define PIN_START 4

#define PORT_SELECT D
#define PIN_SELECT 5

#define PORT_PS D
#define PIN_PS 7

#define LED_CONFIG	(DDRD |= (1<<6))
#define LED_OFF	(PORTD &= ~(1<<6))
#define LED_ON	(PORTD |= (1<<6))
#endif


/**********************************************************
 * gamepad button defines
 */

#define _check_input(port, pin)  _input(port) & (1 << pin)
#define check_input(input)  _check_input(_port(input), _pin(input))

#define GAMEPAD_CIRCLE_ON	    (check_input(CIRCLE))
#define GAMEPAD_CROSS_ON	    (check_input(CROSS))
#define GAMEPAD_TRIANGLE_ON	  (check_input(TRIANGLE))
#define GAMEPAD_SQUARE_ON	    (check_input(SQUARE))

#define GAMEPAD_R1_ON	        (check_input(R1))
#define GAMEPAD_R2_ON	        (check_input(R2))
#define GAMEPAD_L1_ON	        (check_input(L1))
#define GAMEPAD_L2_ON	        (check_input(L2))

#define GAMEPAD_UP_ON	        (check_input(UP))
#define GAMEPAD_DOWN_ON	      (check_input(DOWN))
#define GAMEPAD_LEFT_ON       (check_input(LEFT))
#define GAMEPAD_RIGHT_ON	    (check_input(RIGHT))

#define GAMEPAD_START_ON		  (check_input(START))
#define GAMEPAD_SELECT_ON	    (check_input(SELECT))
#define GAMEPAD_PS_ON	        (check_input(PS))
#define GAMEPAD_REBOOT_ON	    (0)

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
#define __pullup_input(port, pin)  DDR ## port &= ~(1 << pin);  PORT ## port |= (1 << pin);
#define _pullup_input(port, pin)  __pullup_input(port, pin)
#define pullup_input(input)  _pullup_input(_port(input), _pin(input))
    pullup_input(CIRCLE);
    pullup_input(CROSS);
    pullup_input(TRIANGLE);
    pullup_input(SQUARE);
    pullup_input(R1);
    pullup_input(R2);
    pullup_input(L1);
    pullup_input(L2);
    pullup_input(UP);
    pullup_input(DOWN);
    pullup_input(LEFT);
    pullup_input(RIGHT);
    pullup_input(START);
    pullup_input(SELECT);
    pullup_input(PS);

    LED_CONFIG;
}

/**********************************************************
 * read pins and set buttons masks
 */ 

void gamepad_read(void) {
#define __read_input(port, pin)  _input(port) |= ~(PIN ## port) & (1 << pin);
#define _read_input(port, pin)  __read_input(port, pin)
#define read_input(input)  _read_input(_port(input), _pin(input))

    PORT_A_INPUT = 0;
    PORT_B_INPUT = 0;
    PORT_C_INPUT = 0;
    PORT_D_INPUT = 0;
    PORT_E_INPUT = 0;
    PORT_F_INPUT = 0;

    read_input(CIRCLE);
    read_input(CROSS);
    read_input(TRIANGLE);
    read_input(SQUARE);
    read_input(R1);
    read_input(R2);
    read_input(L1);
    read_input(L2);
    read_input(UP);
    read_input(DOWN);
    read_input(LEFT);
    read_input(RIGHT);
    read_input(START);
    read_input(SELECT);
    read_input(PS);

    // feedback on LED
    if (PORT_A_INPUT || PORT_B_INPUT || PORT_C_INPUT || PORT_D_INPUT || PORT_E_INPUT || PORT_F_INPUT)
      LED_ON;
    else
      LED_OFF;

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
