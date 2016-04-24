#include <Arduino.h>
#include <Wire.h>
#include "OLED_128x64.h"

#define ADDRESS 0x3c
#define COMMAND 0x80
#define DATA 0x40

// Hardware parameters
#define __osc_freq (uint8_t)0x08
#define __clk_div (uint8_t)0x00
#define __mux_ratio (uint8_t)0x3F

// Fundamental commands
#define __entire_display_on (uint8_t)0xa4
#define __normal_display (uint8_t)0xa6

#define __contrast (uint8_t)0x8F

Olimex_128x64::Olimex_128x64(void) :
    Adafruit_GFX(128, 64)
{
}

Olimex_128x64::~Olimex_128x64(void)
{

}

void Olimex_128x64::drawPixel(int16_t x, int16_t y, uint16_t color)
{
  unsigned int index = 0;
  unsigned int i = 0;

  x -= 1;
  y -= 1;

  // check for out off range
  if ((x > WIDTH) || (x < 0))
    return;
  if ((y > HEIGHT) || (y < 0))
    return;

  index = (unsigned int) x + ((unsigned int) (y / 8)) * WIDTH;

  buffer[index] |= 1 << (y % 8);
}

void Olimex_128x64::begin(uint8_t sda_pin, uint8_t scl_pin)
{
  Wire.begin(sda_pin, scl_pin);
  begin();
}

void Olimex_128x64::begin(void)
{
  send_command(0xAE);
  send_command_data(0xD5, __osc_freq << 4 | __clk_div);
  send_command_data(0xA8, __mux_ratio);
  send_command_data(0xd3, 0x00);
  send_command_data(0x8d, 0x14);
  send_command(0x40);
  send_command(0xa6);
  send_command(0xa4);
  send_command(0xa1);
  send_command(0xc8);
  // Horizontal mode
  send_command(0x20);
  send_command(0x00);

  send_command_data(0xda, 0x12);
  send_command_data(0x81, __contrast);
  send_command_data(0xd9, 0xf1);
  send_command_data(0xdb, 0x40);
  send_command(0xaf);

  clear_screen();
}

void Olimex_128x64::display(void)
{
  set_column_address();
  set_page_address();

  for (int j = 0; j < 64; j++)
  {
    Wire.beginTransmission(ADDRESS);
    Wire.write(DATA);
    for (int i = 0; i < 16; i++)
    {
      Wire.write(buffer[16 * j + i]);
    }
    Wire.endTransmission();
  }
}

void Olimex_128x64::send_command(uint8_t command)
{
  Wire.beginTransmission(ADDRESS);
  Wire.write(COMMAND);
  Wire.write(command);
  Wire.endTransmission();
}

void Olimex_128x64::send_command_data(uint8_t command, uint8_t data)
{
  Wire.beginTransmission(ADDRESS);
  Wire.write(COMMAND);
  Wire.write(command);
  Wire.write(COMMAND);
  Wire.write(data);
  Wire.endTransmission();
}

void Olimex_128x64::set_page_address()
{
  send_command(0x22);
  send_command(0x00);
  send_command(7);
}

void Olimex_128x64::set_column_address()
{
  send_command(0x21);
  send_command(0x00);
  send_command(127);
}

void Olimex_128x64::clear_screen()
{
  memset(buffer, 0, BUFFER_SIZE);
}

void Olimex_128x64::normal_displaly(void)
{
  send_command(0xa6);
}

void Olimex_128x64::invert_display(void)
{
  send_command(0xa7);
}
