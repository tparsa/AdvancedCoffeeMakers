#include <iostream>
#include <vector>
#include "utils/utils.hpp"


const std::string operators[4] = {"|", "+", "^", "="};
const std::string splitters[3] = {"{", ",", "}"};

std::string get_type(std::string type);
bool is_operator(std::string str);
bool is_splitter(std::string str);
void make_definition_from_splited_line(std::vector<std::string>& definition, std::vector<std::string> splited_line);
std::vector<std::string> make_definition_from_line (std::string line);
std::vector<std::string> extract_machine_from_line(std::string line);
void input_ACM(std::vector<std::vector<std::vector<std::string>>> &machine_trees, std::vector<std::vector<std::vector<std::string>>> &ordered_machines_for_each_test);
void print_test_vvvs(std::vector<std::vector<std::vector<std::string>>> vec);