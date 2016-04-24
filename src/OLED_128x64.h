#ifndef OLED_128x64_H
#define OLED_128x64_H

#include <stdint.h>

#include <Adafruit_GFX.h>

#define BUFFER_SIZE 1024

class Olimex_128x64: public Adafruit_GFX
{
public:
  Olimex_128x64(void);
  virtual ~Olimex_128x64(void);

  virtual void drawPixel(int16_t x, int16_t y, uint16_t color);

  void begin(uint8_t sda_pin, uint8_t scl_pin);
  void begin(void);
  void display(void);

  void clear_screen(void);
  void normal_displaly(void);
  void invert_display(void);

private:
  uint8_t buffer[BUFFER_SIZE];

  void send_command(uint8_t command);
  void send_command_data(uint8_t command, uint8_t data);
  void set_page_address();
  void set_column_address();
};

#endif /* OLED_128x64_H */
