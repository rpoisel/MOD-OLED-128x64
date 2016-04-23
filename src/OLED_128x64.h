#ifndef OLED_128x64_H
#define OLED_128x64_H

#include <stdint.h>

void oled_setup();

void clear_screen();
void invert_screen();
void normal_screen();

void oled_update();

void print_text(uint8_t row, const char *text);
void print_smchar(unsigned char x, unsigned char y, char ch, bool scr);
void print_smtext(unsigned char row, const char *dataPtr, bool scr);
void drawPixel(unsigned char x, unsigned char y);
void drawLine(int x1, int y1, int x2, int y2);
void drawRectangle(int x1, int y1, int x2, int y2);
void drawSolidRectangle(int x1, int y1, int x2, int y2);
void Ellipse4Points(int CX, int CY, int X, int Y);
void drawEllipse(int CX, int CY, int XRadius, int YRadius);
void drawCircle(int x, int y, int r);
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

#endif /* OLED_128x64_H */
