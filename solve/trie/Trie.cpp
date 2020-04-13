//
// Created by nick on 13.04.2020.
//

#include "Trie.hpp"
#include <algorithm>

void Trie::add_word(const std::string &s) {
    Node* node = root_;
    for (unsigned char c : s) {
        if (!node->edges[c]) {
            node->edges[c] = new Node(/*parent =*/ node, /*par_symbol =*/ static_cast<char>(c));
        }
        node = node->edges[c];
    }
    ++node->count;
    update_most_popular(node);
}

std::string Trie::get_word(Node *node) const {
    std::string word;
    while (node != root_) {
        word += node->par_symbol;
        node = node->parent;
    }
    reverse(word.begin(), word.end());
    return word;
}

std::string Trie::autocomplete(const std::string &word) {
   current_ = root_;
   return autocomplete_appending(word);
}

std::string Trie::autocomplete_appending(const std::string &word) {
    for (unsigned char c : word) {
        if (!current_->edges[c]) {
            current_ = nullptr;
            throw BadWordForAutocomplete{};
        }
        current_ = current_->edges[c];
    }
    return get_word(current_->most_popular);
}

void Trie::update_most_popular(Node *node) {
    Node* start = node;
    while (node != nullptr) {
        if (!node->most_popular || node->most_popular->count < start->count) {
            node->most_popular = start;
        }
        node = node->parent;
    }
}
