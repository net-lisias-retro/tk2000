// Copyright (c) 2020 FBLabs
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "pch.h"
#include "WindowSDL.h"
#include "Video.h"

/* Constants */

const byte icon[] = {
	0x42, 0x4D, 0x38, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x02, 0x08, 0x00, 0x00, 0xC3, 0x0E, 0x00, 0x00, 0xC3, 0x0E, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F,
	0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0xFF, 0x7F, 0xFF, 0x7F, 0xFF, 0x7F,
	0xFF, 0x7F, 0x00, 0x00, 0x1F, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x1F, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
	0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x00, 0x00
};

/*************************************************************************************************/
CWindowSDL::CWindowSDL(CVideo* video)
	: mVideo(video), CSubject() {

	mWindow = SDL_CreateWindow("TK2000 Emulator", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, VIDEOWIDTH * 2, VIDEOHEIGHT * 2, SDL_WINDOW_SHOWN);

	if (!mWindow) {
		std::string error{ "Window could not be created! SDL Error: " };
		error.append(SDL_GetError());
		throw std::runtime_error(error);
	}
	SDL_Surface *sIcon{};
	sIcon = SDL_LoadBMP_RW(SDL_RWFromConstMem(icon, sizeof(icon)), 1);
	if (sIcon) {
		SDL_SetColorKey(sIcon, SDL_TRUE, SDL_MapRGB(sIcon->format, 255, 0, 255));
		SDL_SetWindowIcon(mWindow, sIcon);
		SDL_FreeSurface(sIcon);
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer) {
		std::string error{ "Error creating renderer! SDL Error: " };
		error.append(SDL_GetError());
		throw std::runtime_error(error);
	}

	mScreen = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING,
		VIDEOWIDTH, VIDEOHEIGHT * 2);

	if (!mScreen) {
		std::string error{ "Error creating screen texture! SDL Error: " };
		error.append(SDL_GetError());
		throw std::runtime_error(error);
	}
}

/*************************************************************************************************/
CWindowSDL::~CWindowSDL() {
	SDL_DestroyTexture(mScreen);
	SDL_DestroyRenderer(mRenderer);		//Free resources and close SDL
	SDL_DestroyWindow(mWindow);			//Destroy window
	SDL_Quit();							//Quit SDL subsystems
}

/*****************************************************************************/
void CWindowSDL::render() {
	SDL_SetRenderTarget(mRenderer, nullptr);
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(mRenderer);
	char* fb = (char*)mVideo->getFrameBuffer();
	char* ptr;
	int pitch;
	SDL_LockTexture(mScreen, nullptr, (void **)&ptr, &pitch);
	memset(ptr, 0, VIDEOHEIGHT * 2 * pitch);
	for (int i = 0; i < VIDEOHEIGHT; i++) {
		memcpy(ptr, fb, pitch);
		ptr += pitch;
		if (!mScanLines) {
			memcpy(ptr, fb, pitch);
		}
		ptr += pitch;
		fb += pitch;
	}
	SDL_UnlockTexture(mScreen);
	int w, h;
	SDL_GetRendererOutputSize(mRenderer, &w, &h);
	SDL_Rect r{ 0, 0, w, h };
	SDL_RenderCopy(mRenderer, mScreen, NULL, &r);
	SDL_RenderPresent(mRenderer);
}

/*****************************************************************************/
bool CWindowSDL::loop() {
	//Event handler
	SDL_Event e;

	//Handle events on queue
	while (SDL_PollEvent(&e) != 0) {
		switch (e.type) {
		case SDL_QUIT:
			return true;

		case SDL_RENDER_TARGETS_RESET:
			if (!mFullScreen) {
				SDL_SetWindowSize(mWindow, VIDEOWIDTH * 2, VIDEOHEIGHT * 2);
			}
			break;

		case SDL_KEYDOWN:
			if (e.key.keysym.sym == SDLK_F7) {
				setScanline(!mScanLines);
			} else if (e.key.keysym.sym == SDLK_F8) {
				setFullScreen(!mFullScreen);
			} else {
				// Notify all observers
				notify(&e.key);
			}
			break;

		case SDL_KEYUP:
			// Notify all observers
			notify(&e.key);
			break;

		}
	}
	return false;
}

/*****************************************************************************/
void CWindowSDL::setScanline(bool val) noexcept {
	mScanLines = val;
}

/*************************************************************************************************/
void CWindowSDL::setFullScreen(bool val) noexcept {
	mFullScreen = val;
	if (mFullScreen) {
		SDL_DisplayMode dm;
		SDL_GetDesktopDisplayMode(0, &dm);
		SDL_SetWindowSize(mWindow, dm.w, dm.h);
		SDL_SetWindowFullscreen(mWindow, SDL_WINDOW_FULLSCREEN);
	} else {
		SDL_SetWindowFullscreen(mWindow, 0);
		SDL_SetWindowSize(mWindow, VIDEOWIDTH * 2, VIDEOHEIGHT * 2);
	}
}
