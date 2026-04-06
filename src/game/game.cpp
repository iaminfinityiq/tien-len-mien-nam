#include "game.hpp"
#include "../cards/deck.hpp"
#include "../helpers/random.hpp"
#include <vector>
#include <unordered_map>
#include <iostream>
#include "../helpers/terminal.hpp"
#include "../helpers/repr.hpp"
#include <string>
#include "../helpers/valid_number.hpp"
#include "../helpers/strip.hpp"

using namespace helpers;

namespace game {
    Game::Game(std::vector<Hand> &players) {
        this->players = players;
        shuffle(this->players);

        Deck deck = Deck();
        deck.deal_cards(this->players);
    }

    size_t Game::discard_threes() {
        size_t three_spades_guy = 1e18;
        for (size_t i = 0; i < this->players.size(); i++) {
            std::vector<Card> dummy = this->players[i].cards;
            this->players[i].cards = {};
            for (const Card &card : dummy) {
                if (card.value == CardValue::Three) {
                    if (card.type == CardType::Spades) {
                        three_spades_guy = i;
                    }

                    continue;
                }

                this->players[i].receive_card(card);
            }
        }

        return three_spades_guy;
    }

    size_t Game::start_round(const size_t winner_idx) {
        this->discard_pile = DiscardPile();

        std::vector<size_t> remaining_players = {};
        size_t idx = winner_idx;
        size_t iter_count = 0;
        while (iter_count < this->players.size()) {
            if (this->players[idx].cards.empty()) {
                idx++;
                idx %= this->players.size();
                iter_count++;
                continue;
            }

            remaining_players.push_back(idx);
            idx++;
            idx %= this->players.size();
            iter_count++;
        }

        size_t remaining = remaining_players.size();
        std::unordered_map<size_t, bool> out;
        idx = 0;

        if (remaining == 1) {
            return 1000000000000000000;
        }

        while (remaining > 1) {
            if (out[remaining_players[idx]]) {
                idx++;
                idx %= remaining_players.size();
                continue;
            }

            clear();
            std::cout << "It is currently " << this->players[remaining_players[idx]].name << "'s turn. Please pass the device to them\n";
            petc();

            bool result = this->start_turn(remaining_players[idx]);
            if (!result) {
                out[remaining_players[idx]] = true;
                remaining--;
            }

            idx++;
            idx %= remaining_players.size();
            continue;
        }

        for (size_t &player_idx : remaining_players) {
            if (!out[player_idx]) {
                return player_idx;
            }
        }

        return 1000000000000000000;
    }

    bool Game::start_turn(const size_t player_idx) {
        if (this->players[player_idx].cards.empty()) {
            return false;
        }

        std::vector<Card> chosen_cards = {};
        std::vector<Card> temp = this->players[player_idx].cards;
        while (true) {
            clear();
            if (this->discard_pile.last_played.size() > 0) {
                std::cout << "The discard pile currently has " << this->discard_pile.last_played.size() << " cards including:\n";
                for (size_t i = 0; i < this->discard_pile.last_played.size(); i++) {
                    std::cout << "[" << i+1 << "] " << card_repr(this->discard_pile.last_played[i]) << "\n";
                }
            }

            if (chosen_cards.size() > 0) {
                std::cout << "You also chose to play " << chosen_cards.size() << " cards which includes:\n";
                for (size_t i = 0; i < chosen_cards.size(); i++) {
                    std::cout << "[" << i+1 << "] " << card_repr(chosen_cards[i]) << "\n";
                }
            }

            if (this->players[player_idx].cards.empty()) {
                std::cout << this->players[player_idx].name << ", you currently have no cards on your hand\n";
            }  else {
                std::cout << this->players[player_idx].name << ", you currently have " << this->players[player_idx].cards.size() << " cards on your hand. Please take a look at them:\n";
                for (size_t i = 0; i < this->players[player_idx].cards.size(); i++) {
                    std::cout << "[" << i+1 << "] " << card_repr(this->players[player_idx].cards[i]) << "\n";
                }
            }

            if (this->players[player_idx].cards.size() == 0) {
                std::cout << "Leave the input blank and press enter if you want to play the cards you wanted to play, or if you choose not to play any cards, you give up, or press 0 to reset the cards you wanted to play: ";
            } else {
                std::cout << "Type a number from 1 to " << this->players[player_idx].cards.size() << " to play a card to add into the list of cards you wanted to play, or leave the input blank and press enter if you want to play the cards you wanted to play, or if you choose not to play any cards, you give up, or press 0 to reset the cards you wanted to play: ";
            }

            std::string choice;
            std::getline(std::cin, choice);

            choice = strip(choice);
            if (choice == "") {
                clear();
                if (chosen_cards.empty()) {
                    std::cout << "You gave up in the round and will not play until the next round starts\n";
                    petc();
                    return false;
                }

                bool result = this->discard_pile.add_cards(chosen_cards);
                if (result) {
                    std::cout << "Your cards were played successfully\n";
                    petc();
                    return true;
                }

                std::cout << "Your cards did not beat the cards in the discard pile\n";
                petc();
                continue;
            }

            if (choice == "0") {
                clear();
                chosen_cards = {};
                this->players[player_idx].cards = temp;
                continue;
            }

            bool is_valid = valid_number(choice);
            if (!is_valid) {
                clear();
                std::cout << choice << " is not a valid number!\n";
                petc();
                continue;
            }

            bool bounds = check_boundaries(choice, this->players[player_idx].cards.size());
            if (!bounds) {
                clear();
                std::cout << choice << " is not a valid card number!\n";
                petc();
                continue;
            }

            size_t card_value = std::stoull(choice);
            Card card = this->players[player_idx].cards[card_value-1];

            this->players[player_idx].cards.erase(this->players[player_idx].cards.begin()+card_value-1);
            chosen_cards.push_back(card);
        }

        return false;
    }
}