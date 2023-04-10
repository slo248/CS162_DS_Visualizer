#include "Figure.h"

Figure::~Figure()
{
    delete hCircle;
    delete sCircle;
}