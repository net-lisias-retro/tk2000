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

#pragma once

#include "Subject.h"

/* Prototypes */

class CVideo;

/*************************************************************************************************/
class CWindowSDL final : public CSubject<SDL_KeyboardEvent> {
public:
	CWindowSDL(CVideo& video);
	~CWindowSDL();
	// Native
	void render();
	bool loop();
private:
	SDL_Window* mWindow{};
	SDL_Renderer* mRenderer{};
	SDL_Texture* mScreen{};
	TTF_Font* mFont{};
	bool mInMenu = false;
	bool mScanLines{ false };
	CVideo& mVideo;
	bool mFullScreen{ false };
private:
	void setScanline(bool val) noexcept;
	void setFullScreen(bool val) noexcept;
};
