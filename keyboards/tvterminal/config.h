// Copyright 2022 Elliot Powell (@Elliot Powell)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define ENCODERS_PAD_A { C13 }
#define ENCODERS_PAD_B { C14 }
#define ENCODER_RESOLUTION 2

#define PMW3389_CS_PIN A8
#define PMW3360_LIFTOFF_DISTANCE 0x03
#define SPI_DRIVER SPID2
#define SPI_SCK_PIN	    B13
#define SPI_MOSI_PIN	B14
#define SPI_MISO_PIN	B15
#define SPI_SCK_PAL_MODE	5
#define SPI_MOSI_PAL_MODE	5
#define SPI_MISO_PAL_MODE	5
