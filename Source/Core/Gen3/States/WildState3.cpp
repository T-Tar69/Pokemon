/*
 * This file is part of PokéFinder
 * Copyright (C) 2017-2022 by Admiral_Fish, bumba, and EzPzStreamz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
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

#include "WildState3.hpp"
#include <Core/Parents/PersonalInfo.hpp>
#include <Core/Util/Nature.hpp>

constexpr int order[6] = { 0, 1, 2, 5, 3, 4 };

WildGeneratorState3::WildGeneratorState3(u32 advances, u32 pid, u8 nature, u16 iv1, u16 iv2, u16 tsv, u8 level, u8 encounterSlot,
                                         u16 specie, const PersonalInfo *info) :
    WildGeneratorState(advances)
{
    this->level = level;
    this->encounterSlot = encounterSlot;
    this->specie = specie;

    this->pid = pid;
    ability = pid & 1;
    abilityIndex = info->getAbility(ability);
    this->nature = nature;

    u16 psv = ((pid >> 16) ^ (pid & 0xffff));
    if (tsv == psv)
    {
        shiny = 2; // Square
    }
    else if ((tsv ^ psv) < 8)
    {
        shiny = 1; // Star
    }
    else
    {
        shiny = 0;
    }

    switch (info->getGender())
    {
    case 255: // Genderless
        gender = 2;
        break;
    case 254: // Female
        gender = 1;
        break;
    case 0: // Male
        gender = 0;
        break;
    default: // Random gender
        gender = (pid & 255) < info->getGender();
        break;
    }

    ivs[0] = iv1 & 31;
    ivs[1] = (iv1 >> 5) & 31;
    ivs[2] = (iv1 >> 10) & 31;
    ivs[3] = (iv2 >> 5) & 31;
    ivs[4] = (iv2 >> 10) & 31;
    ivs[5] = iv2 & 31;

    u8 h = 0;
    u8 p = 0;
    for (int i = 0; i < 6; i++)
    {
        h += (ivs[order[i]] & 1) << i;
        p += ((ivs[order[i]] >> 1) & 1) << i;

        u16 stat = ((2 * info->getStat(i) + ivs[i]) * level) / 100;
        if (i == 0)
        {
            stats[i] = stat + level + 10;
        }
        else
        {
            stats[i] = Nature::computeStat(stat + 5, nature, i);
        }
    }

    hiddenPower = h * 15 / 63;
    hiddenPowerStrength = 30 + (p * 40 / 63);
}

WildSearcherState3::WildSearcherState3(u32 seed, u32 pid, u8 nature, std::array<u8, 6> ivs, u16 tsv, u8 level, u8 encounterSlot, u16 specie,
                                       const PersonalInfo *info) :
    WildSearcherState(seed)
{
    this->level = level;
    this->encounterSlot = encounterSlot;
    this->specie = specie;

    this->pid = pid;
    ability = pid & 1;
    abilityIndex = info->getAbility(ability);
    this->nature = nature;

    u16 psv = ((pid >> 16) ^ (pid & 0xffff));
    if (tsv == psv)
    {
        shiny = 2; // Square
    }
    else if ((tsv ^ psv) < 8)
    {
        shiny = 1; // Star
    }
    else
    {
        shiny = 0;
    }

    switch (info->getGender())
    {
    case 255: // Genderless
        gender = 2;
        break;
    case 254: // Female
        gender = 1;
        break;
    case 0: // Male
        gender = 0;
        break;
    default: // Random gender
        gender = (pid & 255) < info->getGender();
        break;
    }

    this->ivs = ivs;

    u8 h = 0;
    u8 p = 0;
    for (int i = 0; i < 6; i++)
    {
        h += (ivs[order[i]] & 1) << i;
        p += ((ivs[order[i]] >> 1) & 1) << i;

        u16 stat = ((2 * info->getStat(i) + ivs[i]) * level) / 100;
        if (i == 0)
        {
            stats[i] = stat + level + 10;
        }
        else
        {
            stats[i] = Nature::computeStat(stat + 5, nature, i);
        }
    }

    hiddenPower = h * 15 / 63;
    hiddenPowerStrength = 30 + (p * 40 / 63);
}
