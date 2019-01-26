#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils/utils.hpp"

using namespace std;

const string operators[4] = {"|", "+", "^", "="};
const string splitters[3] = {"{", ",", "}"};

string get_type(string type){
    if(type == "+")
        return "Normal";
    else if(type == "^")
        return "Xor";
    else if(type == "|")
        return "Or";
    return "Normal";
}

bool is_operator(string str){
    for (string op : operators)
        if(str == op)
            return true;
    return false;
}

bool is_splitter(string str){
    for (string spl : splitters)
        if(str == spl)
            return true;
    return false;
}

void make_definition_from_splited_line(vector<string>& definition, vector<string> splited_line){
    for (string str : splited_line)
        if(is_operator(str))
            continue;
        else definition.push_back(str);
}

vector<string> make_definition_from_line (string line){
    vector<string> splited_line = split(line);
    string type = ((int)splited_line.size() > 3) ? splited_line[3] : "Normal";
    type = get_type(type);
    vector<string> definition;
    definition.push_back(type);
    make_definition_from_splited_line(definition, splited_line);
    return definition;
}

vector<string> extract_machine_from_line(string line){
    vector<string> splited_line = split(line);
    vector<string> ret;
    for (int i = 0; i < (int)splited_line.size(); i++)
        if(!is_splitter(splited_line[i]))
            ret.push_back(splited_line[i]);
    return ret;
}

void input(vector<vector<vector<string>>> &machine_trees, vector<vector<vector<string>>> &ordered_machines_for_each_test){
    string line;
    bool orders = false;
    vector<vector<string>> machine_tree;
    vector<vector<string>> ordered_machines;
    while(getline(cin, line)){
        if(line == "###")
            break;
        else if(line == "##"){
            machine_trees.push_back(machine_tree);
            ordered_machines_for_each_test.push_back(ordered_machines);
            machine_tree.clear();
            ordered_machines.clear();
            orders = false;
            continue;
        }
        else if(line == "#"){
            orders = true;
            continue;
        }
        if(!orders)
            machine_tree.push_back(make_definition_from_line(line));
        else
            ordered_machines.push_back(extract_machine_from_line(line));
    }
}

void print_test_vvvs(vector<vector<vector<string>>> vec){
    for (int i = 0; i < (int)vec.size(); i++){
        for (int j = 0; j < (int)vec[i].size(); j++){
            for (int k = 0; k < (int)vec[i][j].size(); k++)
                cout << vec[i][j][k] << " ";
            cout << endl;
        }
        cout << "+++" << endl;
    }
}

void proceed(){
    vector<vector<vector<string>>> machine_trees;
    vector<vector<vector<string>>> ordered_machines;
    input(machine_trees, ordered_machines);
    cout << "dafuq" << endl;
    print_test_vvvs(machine_trees);
    print_test_vvvs(ordered_machines);
}

int main(){
    proceed();
}