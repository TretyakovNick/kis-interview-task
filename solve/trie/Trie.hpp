//
// Created by nick on 13.04.2020.
//

#ifndef KIS_INTERVIEW_TASK_TRIE_HPP
#define KIS_INTERVIEW_TASK_TRIE_HPP

#pragma once

#include "Node.hpp"
#include <string>

struct BadWordForAutocomplete : std::exception {};

class Trie {
public:
    Trie(Node* root) : root_(root), current_(root) {}
    Trie() : Trie(new Node(nullptr, -1)) {}

    void add_word(const std::string &s);

    std::string autocomplete(const std::string &word);

    std::string autocomplete_appending(const std::string &word);

private:
    friend Node;
    Node* root_;
    Node* current_;

    std::string get_word(Node *node) const;

    void update_most_popular(Node *node);
};


#endif //KIS_INTERVIEW_TASK_TRIE_HPP
