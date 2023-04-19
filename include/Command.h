#ifndef COMMAND_H
#define COMMAND_H

struct Command
{
    int option;
    int suboption;
    int input1;
    int input2;
    std::vector<int> list;
};

#endif // COMMAND_H