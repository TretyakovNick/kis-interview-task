//
// Created by nick on 13.04.2020.
//

#ifndef KIS_INTERVIEW_TASK_NODE_HPP
#define KIS_INTERVIEW_TASK_NODE_HPP

#pragma once
#include <vector>

struct Node {
    Node() = default;
    Node(Node* parent, char par_symbol)
        : edges(256, nullptr),
        parent(parent),
        par_symbol(par_symbol),
        most_popular(nullptr),
        count(0) {}

    std::vector<Node*> edges;
    Node* parent;
    char par_symbol;
    Node* most_popular;
    size_t count;
};


#endif //KIS_INTERVIEW_TASK_NODE_HPP
