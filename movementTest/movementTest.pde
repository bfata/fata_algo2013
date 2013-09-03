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

// Default FPS in Processing is 60 FPS
// Resolution on a flat panel monitor is on average 96 DPI
// Pixel to Inch conversion at this resolution =
// 395 pixels = 4.11 inches = 4.11 inches/frame * 60 = 246.6 inches/second = 14,796 inches/min
// = 887,760 inches/ hour = 887,760 / 63,360 (inches/mile) = 14.011 MPH

// .15 pixels = .0015 inches = .0015 inches/frame * 60 = .09 inches/second = 5.4 inches/min
// = 324 inches/hour = 324 / 63,360 (inches/mile) = .00511 MPH


