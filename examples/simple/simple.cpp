#include <OLED_128x64.h>

void setup(void)
{
    pinMode(8, OUTPUT);
    digitalWrite(8, LOW);
    delay(300);

    Wire.begin(2 /* sda */, 4 /* scl */);

    oled_setup();

    print_text(1," OLIMEX");
    print_smtext(3,(unsigned char *)"     Hello World!",1);
    print_smtext(5,(unsigned char *)"        Sensei will",1);
    print_smtext(6,(unsigned char *)"        teach you the",1);
    print_smtext(7,(unsigned char *)"        Olimexino way",1);
    
    drawLine(1,25,128,25);
    
    drawEllipse(20,70,5,20);
    drawLine(23,52,37,60);
    drawLine(17,52,10,64);
    
    drawCircle(20,40,10);
    drawLine(15,38,18,38);
    drawLine(22,38,25,38);
    drawLine(20,40,21,42);
    drawLine(15,43,16,45);
    drawLine(17,46,20,47);
    
    drawTriangle(5,35,20,28,35,35);
    
    drawRectangle(37,55,40,65);
    drawSolidRectangle(37,54,40,30);
    
    //invert_screen();
    //normal_screen();
    
    oled_update();
    delay(200);
}

void loop(void)
{
}
