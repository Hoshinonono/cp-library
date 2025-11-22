#pragma once
#include <array>
#include <vector>

struct SuffixAutomaton {
    struct Node {
        int link, len;
        std::array<int, 26> next;
        Node() : link(-1), len(0) { next.fill(-1); }
        int& operator[](int p){ return next[p]; }
    };

    std::vector<Node> nodes;
    int last;

    SuffixAutomaton() { nodes.emplace_back(Node()); last = 0; }
    Node& operator[](int p){ return nodes[p]; }
    int size(){ return nodes.size(); }
    void extend(char c) {
        int cv = c - 'a';
        int cur = nodes.size();
        nodes.emplace_back(Node());
        nodes[cur].len = nodes[last].len + 1;
        int p = last;
        while (p != -1 && nodes[p][cv] == -1) {
            nodes[p][cv] = cur;
            p = nodes[p].link;
        }
        if (p == -1) {
            nodes[cur].link = 0;
        } else {
            int q = nodes[p][cv];
            if (nodes[p].len + 1 == nodes[q].len) {
                nodes[cur].link = q;
            } else {
                int clone = nodes.size();
                nodes.push_back(nodes[q]);
                nodes[clone].len = nodes[p].len + 1;
                while (p != -1 && nodes[p][cv] == q) {
                    nodes[p][cv] = clone;
                    p = nodes[p].link;
                }
                nodes[q].link = nodes[cur].link = clone;
            }
        }
        last = cur;
    }
};
