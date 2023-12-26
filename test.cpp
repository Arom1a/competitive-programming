#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

vector<int> split(string ori_str)
{
    int end = ori_str.find(' ');
    int length = count(ori_str.begin(), ori_str.end(), ' ') + 1;
    vector<int> return_array(length);
    for (int i = 0; i < length; i++)
    {
        int piece = stoi(ori_str.substr(0, end));
        return_array[i] = piece;
        ori_str = ori_str.substr(end + 1);
        end = ori_str.find(' ');
    }
    return return_array;
}

// int main(int argc, char** argv) {

//     std::string line;
//     int number;
//     std::vector<int> numbers;

//     std::cout << "Enter numbers separated by spaces: ";
//     std::getline(std::cin, line);
//     std::istringstream stream(line);
//     while (stream >> number)
//         numbers.push_back(number);

//     write_vector(numbers);

// }

int main()
{
    int initial_number;
    string hand_number_str;
    string tile_number_str;

    // cin >> initial_number;
    // cin.ignore(10, '\n');
    // getline(cin, hand_number_str);
    // getline(cin, tile_number_str);

    initial_number = 5923;
    hand_number_str = "27 73 34 99 45 32 17 64 57 18 11";
    tile_number_str = "92 22 50 82";

    int number_of_space;
    number_of_space = count(hand_number_str.begin(), hand_number_str.end(), ' ') + 1;
    vector<int> hand_number = split(hand_number_str);
    number_of_space = count(tile_number_str.begin(), tile_number_str.end(), ' ') + 1;
    vector<int> tile_number = split(tile_number_str);
}