int mide_distancia_servo(){
  int tiempo;
  
  digitalWrite(DIST_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(DIST_TRIG, LOW);
  tiempo=pulseIn(DIST_ECHO, HIGH);

  delay(60);
  
  return tiempo/58;
}
