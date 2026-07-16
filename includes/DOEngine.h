
/*
 * ============================================================================
 * DOEngine
 * Copyright (c) 2026 Victor D. Montero, Aneury Perez
 * All Rights Reserved.
 *
 * Licensed under the MIT License.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * 1. The above copyright notice, this license notice, and this disclaimer
 *    MUST be included in all copies or substantial portions of the Software.
 *
 * 2. This notice may not be removed from the original source files distributed
 *    as part of this project.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * ============================================================================
 */
#ifndef DOENGINE_HPP_DEFINED
#define DOENGINE_HPP_DEFINED

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#ifdef NAMESPACE
#define DOENGINE_NAME_START                                                    \
    namespace doengine                                                         \
    {
#define DOENGINE_NAME_END }
#else
#define DOENGINE_NAME_START namespace doengine
#define DOENGINE_NAME_END
#endif

#ifdef OFF

#include "Application.h"
#include "Event.h"
#include "EventHandler.h"
#include "FPSManager.h"
#include "GameObject.h"
#include "GameStateManager.h"
#include "Geometric.h"
#include "Grids.h"
#include "LinkList.h"
#include "Sprite.h"
#include "TTFText.h"
#include "Tile.h"
#include "Tilemap.h"
#include "UDPPacket.h"
#include "Vector.h"
#include "defines.h"
#include "sort.h"

#endif

#endif