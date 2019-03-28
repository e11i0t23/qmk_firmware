#include "keyboard.h"
#include "ch.h"
#include "hal.h"
#include "led_custom.h"
#include "util.h"
#include "quantum.h"

#include "tmk_core/common/eeprom.h"

#include "ws2812.h"

#ifdef BACKLIGHT_ENABLE
backlight_config_t kb_backlight_config = {
  .enable = true,
  .breathing = true,
  .level = BACKLIGHT_LEVELS
};
#endif


bool eeprom_is_valid(void)
{
	return (eeprom_read_word(((void*)EEPROM_MAGIC_ADDR)) == EEPROM_MAGIC &&
			eeprom_read_byte(((void*)EEPROM_VERSION_ADDR)) == EEPROM_VERSION);
}

void eeprom_set_valid(bool valid)
{
	eeprom_update_word(((void*)EEPROM_MAGIC_ADDR), valid ? EEPROM_MAGIC : 0xFFFF);
	eeprom_update_byte(((void*)EEPROM_VERSION_ADDR), valid ? EEPROM_VERSION : 0xFF);
}

void eeprom_reset(void)
{
	eeprom_set_valid(false);
	eeconfig_disable();
}

void save_backlight_config_to_eeprom(){
#ifdef BACKLIGHT_ENABLE
  eeprom_update_byte((uint8_t*)EEPROM_CUSTOM_BACKLIGHT, kb_backlight_config.raw);
#endif
}

void load_custom_config(){
#ifdef BACKLIGHT_ENABLE
  kb_backlight_config.raw = eeprom_read_byte((uint8_t*)EEPROM_CUSTOM_BACKLIGHT);
#endif
}

void eeprom_init_kb(void)
{
	// If the EEPROM has the magic, the data is good.
	// OK to load from EEPROM.
	if (eeprom_is_valid()) {
		load_custom_config();
	} else	{
		// Save the magic number last, in case saving was interrupted
		eeprom_set_valid(true);
	}
}

void matrix_init_kb(void){
  	eeprom_init_kb();
      /* MOSI pin*/
    wait_ms(500);

    matrix_init_custom();

#ifdef RGBLIGHT_ENABLE
    palSetPadMode(PORT_WS2812, PIN_WS2812, PAL_MODE_ALTERNATE(0));
    leds_init();
#endif
#ifdef BACKLIGHT_ENABLE
    backlight_init_ports();
#endif
}

void matrix_scan_kb(void)
{
  #ifdef RGBLIGHT_ENABLE
    rgblight_task();
  #endif

    matrix_scan_custom();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
#ifdef BACKLIGHT_ENABLE
    case BL_INC:
      if (record->event.pressed) {
        kb_backlight_config.level = kb_backlight_config.level + 1;
        if(kb_backlight_config.level > BACKLIGHT_LEVELS){
          kb_backlight_config.level = BACKLIGHT_LEVELS;
        }
        backlight_set(kb_backlight_config.level);
        save_backlight_config_to_eeprom();
      }
      return false;
    case BL_TOGG:
      if (record->event.pressed) {
        kb_backlight_config.enable = !kb_backlight_config.enable;
        if(kb_backlight_config.enable){
          backlight_set(kb_backlight_config.level);
        } else {
          backlight_set(0);
        }
        save_backlight_config_to_eeprom();
      }
      return false;

    case BL_DEC:
      if (record->event.pressed) {
        if(kb_backlight_config.level <= 1){
          kb_backlight_config.level = 0;
        } else {
          kb_backlight_config.level = kb_backlight_config.level - 1;
        }
        backlight_set(kb_backlight_config.level);
        save_backlight_config_to_eeprom();
      }
      return false;
    case BL_BRTG:
      if (record->event.pressed) {
        kb_backlight_config.breathing = !kb_backlight_config.breathing;
        breathing_toggle();
        save_backlight_config_to_eeprom();
      }
      return false;
#endif
  }
  return true;
}
