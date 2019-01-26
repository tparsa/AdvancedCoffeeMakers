#include "node.hpp"

Node::Node(std::vector<Node*> _children, std::string _name, std::string _parent_name,  bool _optional){
    name = _name;
    parent_name = _parent_name;
    optional = _optional;
    for (Node* node : _children)
        children.insert(node);
}

bool Node::parent_exists(std::vector<Node*> available_parents){
    if(parent == NULL)
        return true;
    for (Node* par : available_parents)
        if(par == parent)
            return true;
    return false;
}

std::map<Node*, bool> Node::fill_mark_for_validation(std::vector<Node*> available_children){
    std::map<Node*, bool> mark;
    for (Node* node : available_children)
        if(exists_in_children(node))
            mark[node] = true;
    return mark;
}

bool Node::check_all_existence(std::vector<Node*> available_children)
{
    for (Node* node : available_children)
        if(!exists_in_children(node))
            return false;
    return true;
}

bool Normal::validation(std::vector<Node*> available_children){
    std::map<Node*, bool> mark;
    mark = fill_mark_for_validation(available_children);

    for (Node* node : children)
        if(!node->get_optional() && mark[node] == false)
            return false;
    return true;
}

bool Or::validation(std::vector<Node*> available_children){
    std::map<Node*, bool> mark;
    mark = fill_mark_for_validation(available_children);
   // if(!check_all_existence(available_children))
     //   return false;

    return ((int)mark.size() > 0);
}

bool Alternative::validation(std::vector<Node*> available_children){
    std::map<Node*, bool> mark;
    mark = fill_mark_for_validation(available_children);
  //  if(!check_all_existence(available_children))
    //    return false;
    return ((int)mark.size() == 1);
}