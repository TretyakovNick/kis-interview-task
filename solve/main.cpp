//
// Created by nick on 13.04.2020.
//

#include <iostream>
#include <vector>
#include <string>

#include "trie/Trie.hpp"


std::vector <std::string> parse(const std::string& text) {
    std::string word = "";
    std::vector <std::string> words;
    for (char symbol : text) {
        if (symbol == ' ') {
            if (!word.empty()) {
                words.push_back(std::move(word));
            }
            word = "";
        } else {
            word += symbol;
        }
    }
    if (!word.empty()) {
        words.push_back(std::move(word));
    }
    return words;
}

struct BadOperation : std::exception {};
struct NotOneWord: std::exception {};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    setlocale(LC_ALL, "Russian");

    std::string text;
    Trie trie{};
    while (getline(std::cin, text)) {
        std::vector <std::string> words = parse(text);
        std::string type = words[0];
        if (type == "ADD:") {
            for (size_t i = 1; i < words.size(); ++i) {
                trie.add_word(words[i]);
            }
        } else {
            try {
                if (type == "COMPLETE:") {
                    if (words.size() != 2) {
                        throw NotOneWord{};
                    }
                    std::cout << trie.autocomplete(words[1]) << std::endl;
                } else if (type == "APPEND:") {
                    if (words.size() != 2) {
                        throw NotOneWord{};
                    }
                    std::cout << trie.autocomplete_appending(words[1]) << std::endl;
                } else {
                    throw BadOperation{};
                }
            } catch (BadOperation& expr) {
                std::cout << "Unknown operation!" << std::endl;
            } catch (BadWordForAutocomplete& expr) {
                std::cout << "No words with such a prefix!" << std::endl;
            } catch (NotOneWord& expr) {
                std::cout << "Input for complete must contain exactly one word!" << std::endl;
            }
        }
    }
}
