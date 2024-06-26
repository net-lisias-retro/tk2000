// Copyright (c) 2024 FBLabs
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

#include <iostream>
#include <cassert>
#include <cstdint>
#include <chrono>
#include <algorithm>
#include <thread>
#include <array>
#include <queue>
#include <unordered_map>
#include <mutex>
#include <memory>
#include <filesystem>
#ifdef _WIN32
# include <SDL.h>
#else
# include <SDL2/SDL.h>
#endif
