
void led_blink(int bulb_pin){
  digitalWrite(bulb_pin,HIGH);
  delay(700);
  digitalWrite(bulb_pin,LOW);
  delay(700);
}