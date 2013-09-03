float rectPos= 0;

void setup(){
 size (800,600); 
 background (0);
 fill (255,0,0);
}

void draw (){
background (0); 
rect (rectPos, 300, 10,10);
// rectPos = rectPos+395;  fastest
 rectPos = rectPos+.15;  
 // above is the slowest speed. however,
 // at a certain point it just jumps pixels
}


