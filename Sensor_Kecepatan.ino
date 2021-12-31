int freq(){
  unsigned int t;
  TIFR1 |= (1<<ICF1);
  TCNT1 =0;                              //reset timer 1
  while((TIFR1&(1<<ICF1)) == 0); //monitor rising edge
  t=ICR1;
  //Serial.println("detected");
  TIFR1 |= (1<<ICF1);
  while((TIFR1&(1<<ICF1)) == 0); //wait for the next rising edge
  //Serial.println("detected2");
  Serial.println(TIFR1&(TOV1));
  if (TOV1==1){     //check overflow flag
   TIFR1 |= (1<<TOV1);
   return 0;
  }
  else{
   return F_CPU/(ICR1 - t);
  }
}
