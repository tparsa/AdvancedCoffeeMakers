#ifndef __ACMHPP__
#define __ACMHPP__
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include "node.hpp"

enum Type {normalNode, orNode, xorNode};

class ACM {
    private:
        std::vector<Node*> nodes;
        Node* find_node_with_name(std::string name);
        void add_sub_features(std::string feature_name, std::string feature_parent_name, std::vector<std::string> sub_features, Type type, bool optional=0);
        std::map<std::string, int> make_definition_index_map(std::vector<std::vector<std::string>> definitions);
        void dfs_make(const std::vector<std::vector<std::string>>&, const std::map<std::string, int>&, std::map<std::string, bool>&, int idx = 0, std::string parent_name = "", bool optional = false);
        std::vector<std::string> get_sub_features_name(std::vector<std::string>);
        Type get_type(std::string);
        void make_coffee_machines(std::vector<std::vector<std::string>>);
        void set_all_parents();
    public:
        ACM(std::vector<std::vector<std::string>> definitions) { make_coffee_machines(definitions); }
        bool validate_order(std::vector<std::string>);
};

#endif