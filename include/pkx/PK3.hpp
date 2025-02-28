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

#ifndef PK3_HPP
#define PK3_HPP

#include "personal/personal.hpp"
#include "pkx/PKX.hpp"

namespace pksm
{
    class PK3 : public PKX
    {
    protected:
        static constexpr size_t BlockDataLength   = 12;
        static constexpr size_t BlockShuffleStart = 32;
        // Doesn't use pksm::crypto::pkm method because there's no seed stepping
        void crypt(void);
        u16 calcChecksum() const;

    private:
        bool japanese(void) const;
        static int swapBits(int value, int p1, int p2);

        [[nodiscard]] int eggYear(void) const override { return 1900; }

        void eggYear(int) override {}

        [[nodiscard]] int eggMonth(void) const override { return 1; }

        void eggMonth(int) override {}

        [[nodiscard]] int eggDay(void) const override { return 1; }

        void eggDay(int) override {}

        [[nodiscard]] int metYear(void) const override { return 1900; }

        void metYear(int) override {}

        [[nodiscard]] int metMonth(void) const override { return 1; }

        void metMonth(int) override {}

        [[nodiscard]] int metDay(void) const override { return 1; }

        void metDay(int) override {}

    public:
        static constexpr size_t BOX_LENGTH            = 80;
        static constexpr size_t PARTY_LENGTH          = 100;
        static constexpr Species FORMAT_SPECIES_LIMIT = Species::Deoxys;

        PK3(PrivateConstructor, u8* dt, bool party = false, bool directAccess = false);

        [[nodiscard]] std::string_view extension() const override { return ".pk3"; }

        static u8 getUnownForm(u32 pid);

        [[nodiscard]] std::unique_ptr<PK1> convertToG1(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK2> convertToG2(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK4> convertToG4(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK5> convertToG5(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK6> convertToG6(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK7> convertToG7(Sav& save) const override;
        // std::unique_ptr<PB7> convertToLGPE(Sav& save) const override;
        [[nodiscard]] std::unique_ptr<PK8> convertToG8(Sav& save) const override;

        [[nodiscard]] std::unique_ptr<PKX> clone(void) const override;

        [[nodiscard]] Generation generation(void) const override;

        [[nodiscard]] bool isParty(void) const override { return getLength() == PARTY_LENGTH; }

        void decrypt(void) override;
        void encrypt(void) override;
        [[nodiscard]] bool isEncrypted(void) const override;

        [[nodiscard]] u32 encryptionConstant(void) const override;
        void encryptionConstant(u32 v) override;
        [[nodiscard]] u8 currentFriendship(void) const override;
        void currentFriendship(u8 v) override;

        [[nodiscard]] u8 currentHandler(void) const override { return 0; }

        void currentHandler(u8) override {}

        [[nodiscard]] u8 abilityNumber(void) const override;
        void abilityNumber(u8 v) override;
        void setAbility(u8 abilityNumber) override;

        [[nodiscard]] u32 PID(void) const override;
        void PID(u32 v) override;
        [[nodiscard]] u16 TID(void) const override;
        void TID(u16 v) override;
        [[nodiscard]] u16 SID(void) const override;
        void SID(u16 v) override;
        [[nodiscard]] std::string nickname(void) const override;
        void nickname(const std::string_view& v) override;
        [[nodiscard]] Language language(void) const override;
        void language(Language v) override;
        [[nodiscard]] bool flagIsBadEgg(void) const;
        void flagIsBadEgg(bool v);
        [[nodiscard]] bool flagHasSpecies(void) const;
        void flagHasSpecies(bool v);
        [[nodiscard]] bool flagIsEgg(void) const;
        void flagIsEgg(bool v);
        [[nodiscard]] std::string otName(void) const override;
        void otName(const std::string_view& v) override;
        [[nodiscard]] u16 markValue(void) const override;
        void markValue(u16 v) override;
        [[nodiscard]] u16 checksum(void) const override;
        void checksum(u16 v) override;
        [[nodiscard]] u16 sanity(void) const override;
        void sanity(u16 v) override;

        [[nodiscard]] u16 speciesID3(void) const;
        void speciesID3(u16 v);
        [[nodiscard]] Species species(void) const override;
        void species(Species v) override;
        [[nodiscard]] u16 heldItem3(void) const;
        void heldItem3(u16 v);
        [[nodiscard]] u16 heldItem(void) const override;
        void heldItem(u16 v) override;
        void heldItem(const Item& item) override;
        [[nodiscard]] u32 experience(void) const override;
        void experience(u32 v) override;
        [[nodiscard]] u8 otFriendship(void) const override;
        void otFriendship(u8 v) override;
        [[nodiscard]] Ability ability(void) const override;
        void ability(Ability v) override;
        [[nodiscard]] bool abilityBit(void) const;
        void abilityBit(bool v);
        [[nodiscard]] u16 ev(Stat ev) const override;
        void ev(Stat ev, u16 v) override;
        [[nodiscard]] u8 contest(u8 contest) const override;
        void contest(u8 contest, u8 v) override;
        [[nodiscard]] bool hasRibbon(Ribbon rib) const override;
        [[nodiscard]] bool ribbon(Ribbon rib) const override;
        void ribbon(Ribbon rib, bool v) override;
        [[nodiscard]] u8 contestRibbonCount(u8 contest) const;
        void contestRibbonCount(u8 contest, u8 count);

        [[nodiscard]] Move move(u8 move) const override;
        void move(u8 move, Move v) override;

        [[nodiscard]] Move relearnMove(u8) const override { return Move::None; }

        void relearnMove(u8, Move) override {}

        [[nodiscard]] u8 PP(u8 move) const override;
        void PP(u8 move, u8 v) override;
        [[nodiscard]] u8 PPUp(u8 move) const override;
        void PPUp(u8 move, u8 v) override;
        [[nodiscard]] u8 iv(Stat iv) const override;
        void iv(Stat iv, u8 v) override;
        [[nodiscard]] bool egg(void) const override;
        void egg(bool v) override;
        [[nodiscard]] bool nicknamed(void) const override;
        void nicknamed(bool v) override;
        [[nodiscard]] bool fatefulEncounter(void) const override;
        void fatefulEncounter(bool v) override;
        [[nodiscard]] Gender gender(void) const override;
        void gender(Gender g) override;
        [[nodiscard]] u16 alternativeForm(void) const override;
        void alternativeForm(u16 v) override;
        u8 shinyLeaf(void) const;
        void shinyLeaf(u8 v);
        [[nodiscard]] Nature nature(void) const override;
        void nature(Nature v) override;
        bool hiddenAbility(void) const;
        void hiddenAbility(bool v);

        [[nodiscard]] bool hyperTrain(Stat) const override { return false; }

        void hyperTrain(Stat, bool) override {}

        [[nodiscard]] GameVersion version(void) const override;
        void version(GameVersion v) override;

        [[nodiscard]] u16 eggLocation(void) const override { return 0; }

        void eggLocation(u16) override {}

        [[nodiscard]] u16 metLocation(void) const override;
        void metLocation(u16 v) override;
        [[nodiscard]] u8 pkrs(void) const override;
        void pkrs(u8 v) override;
        [[nodiscard]] u8 pkrsDays(void) const override;
        void pkrsDays(u8 v) override;
        [[nodiscard]] u8 pkrsStrain(void) const override;
        void pkrsStrain(u8 v) override;
        [[nodiscard]] Ball ball(void) const override;
        void ball(Ball v) override;
        [[nodiscard]] u8 metLevel(void) const override;
        void metLevel(u8 v) override;
        [[nodiscard]] Gender otGender(void) const override;
        void otGender(Gender v) override;
        [[nodiscard]] u8 encounterType(void) const;
        void encounterType(u8 v);
        [[nodiscard]] u8 characteristic(void) const;

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
            return PersonalRSFRLGE::baseHP(formSpecies());
        }

        [[nodiscard]] inline u8 baseAtk(void) const override
        {
            return PersonalRSFRLGE::baseAtk(formSpecies());
        }

        [[nodiscard]] inline u8 baseDef(void) const override
        {
            return PersonalRSFRLGE::baseDef(formSpecies());
        }

        [[nodiscard]] inline u8 baseSpe(void) const override
        {
            return PersonalRSFRLGE::baseSpe(formSpecies());
        }

        [[nodiscard]] inline u8 baseSpa(void) const override
        {
            return PersonalRSFRLGE::baseSpa(formSpecies());
        }

        [[nodiscard]] inline u8 baseSpd(void) const override
        {
            return PersonalRSFRLGE::baseSpd(formSpecies());
        }

        [[nodiscard]] inline Type type1(void) const override
        {
            return PersonalRSFRLGE::type1(formSpecies());
        }

        [[nodiscard]] inline Type type2(void) const override
        {
            return PersonalRSFRLGE::type2(formSpecies());
        }

        [[nodiscard]] inline u8 genderType(void) const override
        {
            return PersonalRSFRLGE::gender(formSpecies());
        }

        [[nodiscard]] inline u8 baseFriendship(void) const override
        {
            return PersonalRSFRLGE::baseFriendship(formSpecies());
        }

        [[nodiscard]] inline u8 expType(void) const override
        {
            return PersonalRSFRLGE::expType(formSpecies());
        }

        [[nodiscard]] inline Ability abilities(u8 n) const override
        {
            return PersonalRSFRLGE::ability(formSpecies(), n);
        }

        [[nodiscard]] inline u16 formStatIndex(void) const override { return 0; }

    private:
        [[nodiscard]] u16 statImpl(Stat stat) const override;
    };
}

#endif
