#include "DArr.h"
#include "Config.h"

using namespace Config::DArr;

void DArr::checkSize()
{
    if(num.value<curMaxNode) return;
    
    // actually allocate new array with size double of current size
    saveOldMem();

    for(int i=curMaxNode; i<2*curMaxNode; i++){
        listNodeIndex.pushBack(i);
        listNodeIndex.rbegin()->data.position=START_POSITION_INDEX+sf::Vector2f(i*DISTANCE, 0);

        listNodeA.pushBack(-1);
        listNodeA.rbegin()->data.position=START_POSITION_A+sf::Vector2f(i*DISTANCE, 0);
    }

    curMaxNode<<=1;
    //

    // update graph
    
    //
}