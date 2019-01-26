#ifndef __NODEHPP__
#define __NODEHPP__

#include <set>
#include <vector>
#include <map>
#include <string>

class Node {
    protected:
        int number_of_children;
        std::set<Node*> children;
        Node* parent;
        std::string name;
        bool optional;
        bool exists_in_children(Node* node){ return !(children.find(node) == children.end()); }
        std::map<Node*, bool> fill_mark_for_validation(std::vector<Node*> available_children);
        bool check_all_existence(std::vector<Node*> available_children);
    public:
        std::string get_name(){ return name; }
        Node(std::vector<Node*> _children, std::string _name, Node* _parent = NULL,  bool _optional=0);
        bool get_optional() { return optional; }
        virtual bool validation(std::vector<Node*> available_children) = 0;
        bool parent_exists(std::vector<Node*> available_parents);
};

class Normal: public Node  {
    public:
        Normal(std::vector<Node*> _children, std::string _name, Node* _parent = NULL,  bool _optional=0): Node(_children, _name, _parent, _optional) {}
        bool validation(std::vector<Node*> available_children);
};

class Or: public Node {
    public:
        Or(std::vector<Node*> _children, std::string _name, Node* _parent = NULL,  bool _optional=0): Node(_children, _name, _parent, _optional) {}
        bool validation(std::vector<Node*> available_children);
};

class Alternative: public Node{
    public:
        Alternative(std::vector<Node*> _children, std::string _name, Node* _parent = NULL,  bool _optional=0): Node(_children, _name, _parent, _optional) {}
        bool validation(std::vector<Node*> available_children);
};

#endif