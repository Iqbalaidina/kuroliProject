void setup() {
  // put your setup code here, to run once:
  unsigned int t;
  //DDRA = 0xFF;  
  DDRB = 0xFF;         //Data 
  PORTD = 0xFF; 
  TCCR1A = 0;
  TIFR1|= (1<<ICF1);   /* clear input capture flag */
  TCCR1B = 0x41;      /* capture on rising edge */ 

  while ((TIFR1&(1<<ICF1)) == 0);  /* monitor for capture*/
  t = ICR1;     
  TIFR1 |= (1<<ICF1);   /* clear capture flag */

  while ((TIFR1&(1<<ICF1)) == 0);  /* monitor for next rising
          edge capture */

  t = ICR1 - t;       /* period= recent capture-
          previous capture */
  PORTA = t;        /* put period count on PORTA & PORTB */ 
  PORTB = t>>8; 

  while (1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
