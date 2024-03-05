#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define LED_PIN PB5 // pin D13
#define SWITCH_PIN PD2 // pin D2
#define MAX_COUNT 5
volatile int g_nCounter = 0;

void INT0_Init() {
  // Set INT0 to trigger on falling edge
  EICRA = (1 << ISC01); // ISC01 = 1 and ISC00 = 0 for falling edge

  // Enable INT0 interrupt
  EIMSK = (1 << INT0);
}

ISR(INT0_vect) {
  g_nCounter++;
  if (g_nCounter >= MAX_COUNT) {
    PORTB |= (1 << LED_PIN);
    g_nCounter = 0;
  }
}

int main() 
{
  //set switch pin as input
  DDRD &= ~(1 << SWITCH_PIN);
  PORTD |= (1 << SWITCH_PIN);

  // set LED pin as output
  DDRB |= (1 << LED_PIN);
  INT0_Init();
  sei();
  while (1) {
    // wait 1 second
    // PORTB ^= (1 << LED_PIN);
    // _delay_ms(1000);
  }
  return 0;
}