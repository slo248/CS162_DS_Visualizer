#include "SArr.h"
#include "Config.h"

using namespace Config::SArr;

int SArr::search(int value)
{
    assert(Config::MIN_VALUE<=value && value<=Config::MAX_VALUE);

    graph.finishAllSteps();
    codeBox.loadFromFile("code/SArr/search.txt");
    
}
