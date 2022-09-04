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

#ifndef WILDSTATE3_HPP
#define WILDSTATE3_HPP

#include <Core/Parents/States/WildState.hpp>

class PersonalInfo;

/**
 * @brief State class for Gen3 static generator encounters
 */
class WildGeneratorState3 : public WildGeneratorState
{
public:
    /**
     * @brief Construct a new GeneratorState3 object
     *
     * @param advances State advances
     * @param pid PID value
     * @param iv1 First IV call
     * @param iv2 Second IV call
     * @param tsv Trainer shiny value
     * @param level Pokemon level
     * @param info Pokemon personal information
     */
    WildGeneratorState3(u32 advances, u32 pid, u16 iv1, u16 iv2, u16 tsv, u8 level, u8 encounterSlot, u16 specie, const PersonalInfo *info);

    /**
     * @brief Returns the hidden power strength
     *
     * @return Hidden power strength
     */
    u8 getHiddenPowerStrength() const
    {
        return hiddenPowerStrength;
    }

private:
    u8 hiddenPowerStrength;
};

/**
 * @brief State class for Gen3 static searcher encounters
 */
class WildSearcherState3 : public WildSearcherState<u32>
{
public:
    /**
     * @brief Construct a new SearcherState3 object
     *
     * @param seed State seed
     * @param high High 16bits of PID
     * @param low Low 16bits of PID
     * @param ivs Pokemon IVs
     * @param tsv Trainer shiny value
     * @param level Pokemon level
     * @param info Pokemon personal information
     */
    WildSearcherState3(u32 seed, u32 pid, u8 nature, std::array<u8, 6> ivs, u16 tsv, u8 level, u8 encounterSlot, u16 specie,
                       const PersonalInfo *info);

    /**
     * @brief Returns the hidden power strength
     *
     * @return Hidden power strength
     */
    u8 getHiddenPowerStrength() const
    {
        return hiddenPowerStrength;
    }

    void setSeed(u32 seed)
    {
        this->seed = seed;
    }

private:
    u8 hiddenPowerStrength;
};

#endif // WILDSTATE3_HPP