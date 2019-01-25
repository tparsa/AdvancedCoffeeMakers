#include "acm.hpp"

Node* ACM::find_node_with_name (std::string name){
    for (Node* node : nodes){
        if(node->get_name() == name)
            return node;
    }
    return NULL;
}

void ACM::add_sub_features (std::string feature_name, std::string feature_parent_name, std::vector<std::string> sub_features, Type type, bool optional){
    std::vector<Node*> children;
    for (std::string sub_feature_name: sub_features)
        children.push_back(find_node_with_name(sub_feature_name));

    Node* feature_node = NULL;
    if(type == normalNode) feature_node = new Normal(children, feature_name, find_node_with_name(feature_parent_name), optional);
    else if(type == orNode) feature_node = new Or(children, feature_name, find_node_with_name(feature_parent_name), optional);
    else if(type == xorNode) feature_node == new Alternative(children, feature_name, find_node_with_name(feature_parent_name), optional);
}

std::map<std::string, int> ACM::make_definition_index_map(std::vector<std::vector<std::string>> definitions){
    std::map<std::string, int> definition_index;
    int idx = 0;
    for (std::vector<std::string> v : definitions)
        definition_index[v[0]] = ++idx;
    return definition_index;
}

void ACM::make_coffee_machines(std::vector<std::vector<std::string>> definitions){
    std::map<std::string, int> definition_index;
    definition_index = make_definition_index_map(definitions);

    std::map<std::string, bool> mark;
    dfs_make(definitions, definition_index, mark);
    
}

std::vector<std::string> ACM::get_sub_features_name(std::vector<std::string> definition){
    std::vector<std::string> ret;
    for (int i = 2; i < (int)definition.size(); i++)
        ret.push_back(definition[i]);
    return ret;
}

Type ACM::get_type(std::string type){
    if(type == "Normal")
        return normalNode;
    else if(type == "Or")
        return orNode;
    else if(type == "Xor")
        return xorNode;
    return normalNode;
}

void ACM::dfs_make(const std::vector<std::vector<std::string>> &definitions, const std::map<std::string, int> &definition_index, std::map<std::string, bool> &mark, int idx, std::string parent_name, bool optional){
    std::string curr_node_name = definitions[idx][1];
    mark[curr_node_name] = true;
    for (int i = 2; i < (int)definitions[idx].size(); i++)
    {
        std::string next_node_name = definitions[idx][i];
        bool next_node_optional = false;
        if(next_node_name[0] == '?')
        {
            next_node_optional = true;
            next_node_name = next_node_name.substr(1);
        }
        if(!mark[next_node_name])
            dfs_make(definitions, definition_index, mark, definition_index.at(next_node_name) - 1, curr_node_name, next_node_optional);
        else{
            printf("Error in input: redefining %s!\n", next_node_name.c_str());
            return;
        }
    }
    add_sub_features(curr_node_name, parent_name, get_sub_features_name(definitions[idx]) , get_type(definitions[idx][0]), optional);
}