/*
 *   This file is part of PKSM-Core
 *   Copyright (C) 2016-2022 Bernardo Giordano, Admiral Fish, piepie62
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
 *       * Requiring preservation of specified reasonable legal notices or
 *         author attributions in that material or in the Appropriate Legal
 *         Notices displayed by works containing it.
 *       * Prohibiting misrepresentation of the origin of that material,
 *         or requiring that modified versions of such material be marked in
 *         reasonable ways as different from the original version.
 */

#ifndef PK7_HPP
#define PK7_HPP

#include "personal/personal.hpp"
#include "pkx/PKX.hpp"

namespace pksm
{
    class PK7 : public PKX
    {
    private:
        static constexpr size_t BLOCK_LENGTH     = 56;
        static constexpr size_t ENCRYPTION_START = 8;
        [[nodiscard]] int eggYear(void) const override;
        void eggYear(int v) override;
        [[nodiscard]] int eggMonth(void) const override;
        void eggMonth(int v) override;
        [[nodiscard]] int eggDay(void) const override;
        void eggDay(int v) override;
        [[nodiscard]] int metYear(void) const override;
        void metYear(int v) override;
        [[nodiscard]] int metMonth(void) const override;
        void metMonth(int v) override;
        [[nodiscard]] int metDay(void) const override;
        void metDay(int v) override;

    protected:
        static constexpr u8 hyperTrainLookup[6] = {0, 1, 2, 5, 3, 4};

    public:
        static constexpr size_t BOX_LENGTH            = 232;
        static constexpr size_t PARTY_LENGTH          = 260;
        static constexpr Species FORMAT_SPECIES_LIMIT = Species::Zeraora;

        PK7(PrivateConstructor, u8* dt, bool party = false, bool directAccess = false);

        [[nodiscard]] std::string_view extension() const override { return ".pk7"; }

        [[nodiscard]] std::unique_ptr<PK1> convertToG1(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK2> convertToG2(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK3> convertToG3(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK4> convertToG4(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK5> convertToG5(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK6> convertToG6(Sav& save) const override;
        // std::unique_ptr<PKX> convertToLGPE(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK8> convertToG8(Sav& save) const override;

        [[nodiscard]] std::unique_ptr<PKX> clone(void) const override;

        [[nodiscard]] Generation generation(void) const override;
        void decrypt(void) override;
        void encrypt(void) override;
        [[nodiscard]] bool isEncrypted(void) const override;

        [[nodiscard]] bool isParty(void) const override { return getLength() == PARTY_LENGTH; }

        [[nodiscard]] u32 encryptionConstant(void) const override;
        void encryptionConstant(u32 v) override;
        [[nodiscard]] u16 sanity(void) const override;
        void sanity(u16 v) override;
        [[nodiscard]] u16 checksum(void) const override;
        void checksum(u16 v) override;
        [[nodiscard]] Species species(void) const override;
        void species(Species v) override;
        [[nodiscard]] u16 heldItem(void) const override;
        void heldItem(u16 v) override;
        [[nodiscard]] u16 TID(void) const override;
        void TID(u16 v) override;
        [[nodiscard]] u16 SID(void) const override;
        void SID(u16 v) override;
        [[nodiscard]] u32 experience(void) const override;
        void experience(u32 v) override;
        [[nodiscard]] Ability ability(void) const override;
        void ability(Ability v) override;
        [[nodiscard]] u8 abilityNumber(void) const override;
        void abilityNumber(u8 v) override;
        void setAbility(u8 abilityNumber) override;
        [[nodiscard]] u16 markValue(void) const override;
        void markValue(u16 v) override;
        [[nodiscard]] u32 PID(void) const override;
        void PID(u32 v) override;
        [[nodiscard]] Nature nature(void) const override;
        void nature(Nature v) override;
        [[nodiscard]] bool fatefulEncounter(void) const override;
        void fatefulEncounter(bool v) override;
        [[nodiscard]] Gender gender(void) const override;
        void gender(Gender g) override;
        [[nodiscard]] u16 alternativeForm(void) const override;
        void alternativeForm(u16 v) override;
        [[nodiscard]] u16 ev(Stat ev) const override;
        void ev(Stat ev, u16 v) override;
        [[nodiscard]] u8 contest(u8 contest) const override;
        void contest(u8 contest, u8 v) override;

        [[nodiscard]] u8 pelagoEventStatus(void) const;
        void pelagoEventStatus(u8 v);

        [[nodiscard]] u8 pkrs(void) const override;
        void pkrs(u8 v) override;
        [[nodiscard]] u8 pkrsDays(void) const override;
        void pkrsDays(u8 v) override;
        [[nodiscard]] u8 pkrsStrain(void) const override;
        void pkrsStrain(u8 v) override;
        [[nodiscard]] bool hasRibbon(Ribbon rib) const override;
        [[nodiscard]] bool ribbon(Ribbon rib) const override;
        void ribbon(Ribbon rib, bool v) override;
        [[nodiscard]] u8 ribbonContestCount(void) const;
        void ribbonContestCount(u8 v);
        [[nodiscard]] u8 ribbonBattleCount(void) const;
        void ribbonBattleCount(u8 v);

        [[nodiscard]] std::string nickname(void) const override;
        void nickname(const std::string_view& v) override;
        [[nodiscard]] Move move(u8 move) const override;
        void move(u8 move, Move v) override;
        [[nodiscard]] u8 PP(u8 move) const override;
        void PP(u8 move, u8 v) override;
        [[nodiscard]] u8 PPUp(u8 move) const override;
        void PPUp(u8 move, u8 v) override;
        [[nodiscard]] Move relearnMove(u8 move) const override;
        void relearnMove(u8 move, Move v) override;
        [[nodiscard]] u8 iv(Stat iv) const override;
        void iv(Stat iv, u8 v) override;

        [[nodiscard]] bool egg(void) const override;
        void egg(bool v) override;
        [[nodiscard]] bool nicknamed(void) const override;
        void nicknamed(bool v) override;

        [[nodiscard]] std::string htName(void) const;
        void htName(const std::string_view& v);
        [[nodiscard]] Gender htGender(void) const;
        void htGender(Gender v);
        [[nodiscard]] u8 currentHandler(void) const override;
        void currentHandler(u8 v) override;
        [[nodiscard]] u8 geoRegion(u8 region) const;
        void geoRegion(u8 region, u8 v);
        [[nodiscard]] u8 geoCountry(u8 country) const;
        void geoCountry(u8 country, u8 v);
        [[nodiscard]] u8 htFriendship(void) const;
        void htFriendship(u8 v);
        [[nodiscard]] u8 htAffection(void) const;
        void htAffection(u8 v);
        [[nodiscard]] u8 htIntensity(void) const;
        void htIntensity(u8 v);
        [[nodiscard]] u8 htMemory(void) const;
        void htMemory(u8 v);
        [[nodiscard]] u8 htFeeling(void) const;
        void htFeeling(u8 v);
        [[nodiscard]] u16 htTextVar(void) const;
        void htTextVar(u16 v);
        [[nodiscard]] u8 fullness(void) const;
        void fullness(u8 v);
        [[nodiscard]] u8 enjoyment(void) const;
        void enjoyment(u8 v);
        // TODO
        // u32 formDuration(void) const;
        // void formDuration(u32 v);

        [[nodiscard]] std::string otName(void) const override;
        void otName(const std::string_view& v) override;
        [[nodiscard]] u8 otFriendship(void) const override;
        void otFriendship(u8 v) override;
        [[nodiscard]] u8 otAffection(void) const;
        void otAffection(u8 v);
        [[nodiscard]] u8 otIntensity(void) const;
        void otIntensity(u8 v);
        [[nodiscard]] u8 otMemory(void) const;
        void otMemory(u8 v);
        [[nodiscard]] u16 otTextVar(void) const;
        void otTextVar(u16 v);
        [[nodiscard]] u8 otFeeling(void) const;
        void otFeeling(u8 v);
        [[nodiscard]] u16 eggLocation(void) const override;
        void eggLocation(u16 v) override;
        [[nodiscard]] u16 metLocation(void) const override;
        void metLocation(u16 v) override;
        [[nodiscard]] Ball ball(void) const override;
        void ball(Ball v) override;
        [[nodiscard]] u8 metLevel(void) const override;
        void metLevel(u8 v) override;
        [[nodiscard]] Gender otGender(void) const override;
        void otGender(Gender v) override;

        [[nodiscard]] bool hyperTrain(Stat stat) const override;
        void hyperTrain(Stat stat, bool v) override;

        [[nodiscard]] GameVersion version(void) const override;
        void version(GameVersion v) override;
        [[nodiscard]] u8 country(void) const;
        void country(u8 v);
        [[nodiscard]] u8 region(void) const;
        void region(u8 v);
        [[nodiscard]] u8 consoleRegion(void) const;
        void consoleRegion(u8 v);
        [[nodiscard]] Language language(void) const override;
        void language(Language v) override;

        [[nodiscard]] u8 currentFriendship(void) const override;
        void currentFriendship(u8 v) override;
        [[nodiscard]] u8 oppositeFriendship(void) const;
        void oppositeFriendship(u8 v);
        void refreshChecksum(void) override;
        [[nodiscard]] Type hpType(void) const override;
        void hpType(Type v) override;
        [[nodiscard]] u16 TSV(void) const override;
        [[nodiscard]] u16 PSV(void) const override;
        [[nodiscard]] u8 level(void) const override;
        void level(u8 v) override;
        [[nodiscard]] bool shiny(void) const override;
        void shiny(bool v) override;
        [[nodiscard]] u16 formSpecies(void) const override;

        [[nodiscard]] int partyCurrHP(void) const override;
        void partyCurrHP(u16 v) override;
        [[nodiscard]] int partyStat(Stat stat) const override;
        void partyStat(Stat stat, u16 v) override;
        [[nodiscard]] int partyLevel() const override;
        void partyLevel(u8 v) override;
        void updatePartyData(void) override;

        [[nodiscard]] inline u8 baseHP(void) const override
        {
            return PersonalSMUSUM::baseHP(formSpecies());
        }

        [[nodiscard]] inline u8 baseAtk(void) const override
        {
            return PersonalSMUSUM::baseAtk(formSpecies());
        }

        [[nodiscard]] inline u8 baseDef(void) const override
        {
            return PersonalSMUSUM::baseDef(formSpecies());
        }

        [[nodiscard]] inline u8 baseSpe(void) const override
        {
            return PersonalSMUSUM::baseSpe(formSpecies());
        }

        [[nodiscard]] inline u8 baseSpa(void) const override
        {
            return PersonalSMUSUM::baseSpa(formSpecies());
        }

        [[nodiscard]] inline u8 baseSpd(void) const override
        {
            return PersonalSMUSUM::baseSpd(formSpecies());
        }

        [[nodiscard]] inline Type type1(void) const override
        {
            return PersonalSMUSUM::type1(formSpecies());
        }

        [[nodiscard]] inline Type type2(void) const override
        {
            return PersonalSMUSUM::type2(formSpecies());
        }

        [[nodiscard]] inline u8 genderType(void) const override
        {
            return PersonalSMUSUM::gender(formSpecies());
        }

        [[nodiscard]] inline u8 baseFriendship(void) const override
        {
            return PersonalSMUSUM::baseFriendship(formSpecies());
        }

        [[nodiscard]] inline u8 expType(void) const override
        {
            return PersonalSMUSUM::expType(formSpecies());
        }

        [[nodiscard]] inline Ability abilities(u8 n) const override
        {
            return PersonalSMUSUM::ability(formSpecies(), n);
        }

        [[nodiscard]] inline u16 formStatIndex(void) const override
        {
            return PersonalSMUSUM::formStatIndex(formSpecies());
        }

    private:
        [[nodiscard]] u16 statImpl(Stat stat) const override;
    };
}

#endif
