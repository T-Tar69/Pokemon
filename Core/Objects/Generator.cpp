/*
 * This file is part of PokéFinder
 * Copyright (C) 2017 by Admiral_Fish and bumba
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "Generator.hpp"

/* Generator is the parent for all generation(3-7) generators.
 * This class doesn't provide much functionality as that is
 * the purpose of the children for each specific generation.
 */

// Default constructor
Generator::Generator()
{
    maxResults = 100000;
    initialFrame = 1;
    initialSeed = 0;
    tid = 12345;
    sid = 54321;
}