#include "SArr.h"
#include "Config.h"

using namespace Config::SArr;

void SArr::insertFront(int value)
{
    assert(MIN_NODE<=num.value && num.value<MAX_NODE);
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/insertFront.txt");
}