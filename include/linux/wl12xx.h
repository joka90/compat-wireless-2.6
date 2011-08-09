/*
 * This file is part of wl12xx
 *
 * Copyright (C) 2009 Nokia Corporation
 *
 * Contact: Luciano Coelho <luciano.coelho@nokia.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef _LINUX_WL12XX_H
#define _LINUX_WL12XX_H

#define WMPA_NUMBER_OF_SECTIONS	3
#define WMPA_NUMBER_OF_BUFFERS	160
#define WMPA_SECTION_HEADER	24
#define WMPA_SECTION_SIZE_0	(WMPA_NUMBER_OF_BUFFERS * 64)
#define WMPA_SECTION_SIZE_1	(WMPA_NUMBER_OF_BUFFERS * 256)
#define WMPA_SECTION_SIZE_2	(WMPA_NUMBER_OF_BUFFERS * 2048)

/* The board reference clock values */
enum {
	WL12XX_REFCLOCK_19 = 0,	/* 19.2 MHz */
	WL12XX_REFCLOCK_26 = 1,	/* 26 MHz */
	WL12XX_REFCLOCK_38 = 2,	/* 38.4 MHz */
	WL12XX_REFCLOCK_54 = 3,	/* 54 MHz */
};

struct wl12xx_platform_data {
	int (*set_power)(int val);
	int (*set_reset)(int val);
	int (*set_carddetect)(int val);
	/* SDIO only: IRQ number if WLAN_IRQ line is used, 0 for SDIO IRQs */
	int irq;
	bool use_eeprom;
	int board_ref_clock;
};

#ifdef CONFIG_WL12XX_PLATFORM_DATA

int wl12xx_set_platform_data(const struct wl12xx_platform_data *data);

#else

static inline
int wl12xx_set_platform_data(const struct wl12xx_platform_data *data)
{
	return -ENOSYS;
}

#endif

const struct wl12xx_platform_data *wl12xx_get_platform_data(void);

#endif
