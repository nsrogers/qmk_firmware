/* Buttons to USB Keyboard Example

   You must select Keyboard from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(14, 10);
Bounce button1 = Bounce(15, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(16, 10);  // which is appropriate for
Bounce button3 = Bounce(17, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(18, 10);
Bounce button5 = Bounce(19, 10);  // if a button is too "sensitive"


void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();


  // Check each button for "falling" edge.
  // Type a message on the Keyboard when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
 /* if (button0.fallingEdge()) {
    Keyboard.print("B0 press");
  }
  if (button1.fallingEdge()) {
    Keyboard.print("B1 press");
  }
  if (button2.fallingEdge()) {
    Keyboard.print("B2 press");
  }
  if (button3.fallingEdge()) {
    Keyboard.print("B3 press");
  }
  if (button4.fallingEdge()) {
    Keyboard.print("B4 press");
  }
  if (button5.fallingEdge()) {
    Keyboard.print("B5 press");
  }
  */

  // Check each button for "rising" edge
  // Type a message on the Keyboard when each button releases.
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button0.risingEdge()) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT );
    Keyboard.set_key1 (KEYPAD_1); 
    Keyboard.send_now();
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
  if (button1.risingEdge()) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT );
    Keyboard.set_key1 (KEYPAD_2); 
    Keyboard.send_now();
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
  if (button2.risingEdge()) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT );
    Keyboard.set_key1 (KEYPAD_3); 
    Keyboard.send_now();
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
  if (button3.risingEdge()) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT );
    Keyboard.set_key1 (KEYPAD_4); 
    Keyboard.send_now();
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
  if (button4.risingEdge()) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT );
    Keyboard.set_key1 (KEYPAD_5); 
    Keyboard.send_now();
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
  if (button5.risingEdge()) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT );
    Keyboard.set_key1 (KEYPAD_6); 
    Keyboard.send_now();
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
  delay(10);
}
