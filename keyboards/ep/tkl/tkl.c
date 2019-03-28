#include "tkl.h"
#include "print.h"
#include "debug.h"

#include "ch.h"
#include "hal.h"

#include "timer.h"

#include "raw_hid.h"
#include "dynamic_keymap.h"
#include "tmk_core/common/eeprom.h"

// HACK
#include "keyboards/zeal60/zeal60_api.h" // Temporary hack
#include "keyboards/zeal60/zeal60_keycodes.h" // Temporary hack
#include <stdlib.h>

#include "qmk_midi.h"
#include <math.h>
#include "ws2812.h"

#include "keyboard.h"
#include "util.h"
#include "quantum.h"

/* Artificial delay added to get media keys to work in the encoder*/
#define MEDIA_KEY_DELAY 10

uint16_t last_flush;
uint8_t layer;
uint32_t ADCValue;
uint8_t scanNo = 0;
uint8_t encoder_mode = ENC_MODE_VOLUME;
uint8_t enabled_encoder_modes = 0x1F;
div_t volume;
int vol = 0;
MidiDevice* midi_dev;


#define ADC_GRP1_NUM_CHANNELS   1
#define ADC_GRP1_BUF_DEPTH      1
#define steps 30

adcsample_t Last_samples[ADC_GRP1_NUM_CHANNELS * ADC_GRP1_BUF_DEPTH];
adcsample_t samples1[ADC_GRP1_NUM_CHANNELS * ADC_GRP1_BUF_DEPTH];
uint32_t lastVoltage = 0;
int difference = 0;
int current = 0;

static const ADCConversionGroup adcgrpcfg1 = {
  FALSE,
  ADC_GRP1_NUM_CHANNELS,
  NULL,
  NULL,
  ADC_CFGR1_CONT | ADC_CFGR1_RES_12BIT,                                   /* CFGR1 */
  ADC_TR(0, 0),                                     /* TR */
  ADC_SMPR_SMP_1P5,                                 /* SMPR */
  ADC_CHSELR_CHSEL13                                /* CHSELR */
};


#ifdef RAW_ENABLE

void raw_hid_receive( uint8_t *data, uint8_t length )
{
	uint8_t *command_id = &(data[0]);
	uint8_t *command_data = &(data[1]);
	switch ( *command_id )
	{
		case id_get_protocol_version:
		{
			command_data[0] = PROTOCOL_VERSION >> 8;
			command_data[1] = PROTOCOL_VERSION & 0xFF;
			break;
		}
		case id_get_keyboard_value:
		{
      switch( command_data[0])
      {
        case id_uptime:
        {
          uint32_t value = timer_read32();
          command_data[1] = (value >> 24 ) & 0xFF;
          command_data[2] = (value >> 16 ) & 0xFF;
          command_data[3] = (value >> 8 ) & 0xFF;
          command_data[4] = value & 0xFF;
          break;
        }
        case id_encoder_modes:
        {
          command_data[1] = enabled_encoder_modes;
          break;
        }
        case id_encoder_custom:
        {
          // uint8_t custom_encoder_idx = command_data[1];
          // command_data[2] = 0x00;
          // command_data[3] = 0x00;
          // command_data[4] = 0x00;
          // command_data[5] = 0x00;
          // command_data[6] = 0x00;
          // command_data[7] = 0x00;
          break;
        }
        default:
        {
          *command_id = id_unhandled;
          break;
        }
      }
			break;
    }
#ifdef DYNAMIC_KEYMAP_ENABLE
    case id_set_keyboard_value:
    {
      switch(command_data[0]){
        default:
        {
          *command_id = id_unhandled;
          break;
        }
      }
      break;
    }
		case id_dynamic_keymap_get_keycode:
		{
			uint16_t keycode = dynamic_keymap_get_keycode( command_data[0], command_data[1], command_data[2] );
			command_data[3] = keycode >> 8;
			command_data[4] = keycode & 0xFF;
			break;
		}
		case id_dynamic_keymap_set_keycode:
		{
			dynamic_keymap_set_keycode( command_data[0], command_data[1], command_data[2], ( command_data[3] << 8 ) | command_data[4] );
			break;
		}
		case id_dynamic_keymap_reset:
		{
			dynamic_keymap_reset();
			break;
		}
		case id_dynamic_keymap_macro_get_count:
		{
			command_data[0] = dynamic_keymap_macro_get_count();
			break;
		}
		case id_dynamic_keymap_macro_get_buffer_size:
		{
			uint16_t size = dynamic_keymap_macro_get_buffer_size();
			command_data[0] = size >> 8;
			command_data[1] = size & 0xFF;
			break;
		}
		case id_dynamic_keymap_macro_get_buffer:
		{
			uint16_t offset = ( command_data[0] << 8 ) | command_data[1];
			uint16_t size = command_data[2]; // size <= 28
			dynamic_keymap_macro_get_buffer( offset, size, &command_data[3] );
			break;
		}
		case id_dynamic_keymap_macro_set_buffer:
		{
			uint16_t offset = ( command_data[0] << 8 ) | command_data[1];
			uint16_t size = command_data[2]; // size <= 28
			dynamic_keymap_macro_set_buffer( offset, size, &command_data[3] );
			break;
		}
		case id_dynamic_keymap_macro_reset:
		{
			dynamic_keymap_macro_reset();
			break;
		}
		case id_dynamic_keymap_get_layer_count:
		{
			command_data[0] = dynamic_keymap_get_layer_count();
			break;
		}
		case id_dynamic_keymap_get_buffer:
		{
			uint16_t offset = ( command_data[0] << 8 ) | command_data[1];
			uint16_t size = command_data[2]; // size <= 28
			dynamic_keymap_get_buffer( offset, size, &command_data[3] );
			break;
		}
		case id_dynamic_keymap_set_buffer:
		{
			uint16_t offset = ( command_data[0] << 8 ) | command_data[1];
			uint16_t size = command_data[2]; // size <= 28
			dynamic_keymap_set_buffer( offset, size, &command_data[3] );
			break;
		}
#endif // DYNAMIC_KEYMAP_ENABLE
		case id_eeprom_reset:
		{
			eeprom_reset();
			break;
		}
		case id_bootloader_jump:
		{
			// Need to send data back before the jump
			// Informs host that the command is handled
			raw_hid_send( data, length );
			// Give host time to read it
			wait_ms(100);
			bootloader_jump();
			break;
		}
		default:
		{
			// Unhandled message.
			*command_id = id_unhandled;
			break;
		}
	}

	// Return same buffer with values changed
	raw_hid_send( data, length );

}

#endif

uint32_t layer_state_set_kb(uint32_t state) {
  state = layer_state_set_user(state);
  layer = biton32(state);
  return state;
}

void matrix_init_custom(void){
	palSetGroupMode(GPIOC, PAL_PORT_BIT(3),0, PAL_MODE_INPUT_ANALOG);
	//palSetPadMode(PORT_WS2812, PIN_WS2812, PAL_MODE_ALTERNATE(0));
	wait_ms(500);
	//ADC->CCR |= ADC_CCR_VREFEN;
	adcStart(&ADCD1, NULL);
	//midi_device_init(&midi_dev);
	//midi_device_process(&midi_dev);
	//midi_send_start(&midi_device);
}


void matrix_scan_custom(void) {
	if(scanNo == 0){

		adcConvert(&ADCD1, &adcgrpcfg1, samples1, ADC_GRP1_BUF_DEPTH);
		difference = lastVoltage - samples1[0];
		if(difference>30 || difference <-30){
			current = samples1[0];
			volume = div(current, steps);
			vol = round(current/steps);
			//midi_send_cc(midi_device, 15, 20, 25);
			midi_send_cc(&midi_device, 14, 0x7B, vol);
			//midi_send_cc(&midi_device, 14, 0x7A, 12);

		}
		lastVoltage = samples1[0];
	}else if (scanNo == 50){
		scanNo = 0;
	}else{
		scanNo += 1;
	}
}

void encoder_update_kb(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
     uint16_t mapped_code = 0;
	   if (clockwise) {
        mapped_code = handle_encoder_clockwise();
      } else {
        mapped_code = handle_encoder_ccw();
      }
      uint16_t held_keycode_timer = timer_read();
      if(mapped_code != 0){
        register_code(mapped_code);
        while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY){ /* no-op */ }
        unregister_code(mapped_code);
      }
  }
}
