#include "SLL.h"

void SLL::update()
{
    createBtn->update(window);
    if(curBtn==Button::CREATE){
        emptyBtn->update(window);
        randomBtn->update(window);
        loadFromFileBtn->update(window);
    }

    insertBtn->update(window);
    if(curBtn==Button::INSERT){
        insertFrontBtn->update(window);
        insertBackBtn->update(window);
        insertMiddleBtn->update(window);
    }

    updateBtn->update(window);

    searchBtn->update(window);

    deleteBtn->update(window);
    if(curBtn==Button::DELETE){
        deleteFirstBtn->update(window);
        deleteLastBtn->update(window);
        deleteMiddleBtn->update(window);
    }
}
