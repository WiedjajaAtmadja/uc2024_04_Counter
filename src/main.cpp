#include <avr/io.h>
#include <util/delay.h>
#define LED_PIN PB5

int main() 
{
  // set LED pin as output
  DDRB |= (1 << LED_PIN);
  while (1) {
  // wait 1 second
  PORTB ^= (1 << LED_PIN);
  _delay_ms(1000);
  }
  return 0;
}