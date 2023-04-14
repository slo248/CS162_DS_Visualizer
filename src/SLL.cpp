#include "SLL.h"
#include "Random.h"
#include "Config.h"

SLL::SLL(sf::RenderWindow *window, sf::Font *sanf, sf::Sprite* bg, int FPS, sf::CircleShape* circle, ArrowFigure *arrowFig):
    FPS(FPS),
    window(window),
    bg(bg),
    curBtn(Button::NONE),
    isPause(false),
    graph(window, sanf, circle, arrowFig)
{
    graph.clear();
    graph.setVisualType(STEP_BY_STEP);

    createBtn = new Button(sanf, "Create", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    emptyBtn = new Button(sanf, "Empty", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    randomBtn = new Button(sanf, "Random", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    loadFromFileBtn = new Button(sanf, "File", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);

    insertBtn = new Button(sanf, "Insert", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    insertFrontBtn = new Button(sanf, "Front", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    insertBackBtn = new Button(sanf, "Back", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    insertMiddleBtn = new Button(sanf, "Middle", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);

    updateBtn = new Button(sanf, "Update", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);

    searchBtn = new Button(sanf, "Search", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);

    deleteBtn = new Button(sanf, "Delete", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    deleteFirstBtn = new Button(sanf, "First", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    deleteLastBtn = new Button(sanf, "Last", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);
    deleteMiddleBtn = new Button(sanf, "Middle", sf::Vector2f(ButtonConfig::WIDTH,ButtonConfig::HEIGHT), Colors::GREEN, Colors::BLACK, Colors::WHITE);

    sf::Vector2u windowSize = window->getSize();
    createBtn->setPosition(sf::Vector2f(0,windowSize.y-5*createBtn->getSize().y));
    emptyBtn->setPosition(sf::Vector2f(createBtn->getSize().x+10.f,windowSize.y-5*emptyBtn->getSize().y));
    randomBtn->setPosition(sf::Vector2f(2*createBtn->getSize().x+10.f,windowSize.y-5*randomBtn->getSize().y));
    loadFromFileBtn->setPosition(sf::Vector2f(3*createBtn->getSize().x+10.f,windowSize.y-5*loadFromFileBtn->getSize().y));

    insertBtn->setPosition(sf::Vector2f(0,windowSize.y-4*insertBtn->getSize().y));
    insertFrontBtn->setPosition(sf::Vector2f(insertBtn->getSize().x+10.f,windowSize.y-4*insertFrontBtn->getSize().y));
    insertBackBtn->setPosition(sf::Vector2f(2*insertBtn->getSize().x+10.f,windowSize.y-4*insertBackBtn->getSize().y));
    insertMiddleBtn->setPosition(sf::Vector2f(3*insertBtn->getSize().x+10.f,windowSize.y-4*insertMiddleBtn->getSize().y));

    updateBtn->setPosition(sf::Vector2f(0,windowSize.y-3*updateBtn->getSize().y));

    searchBtn->setPosition(sf::Vector2f(0,windowSize.y-2*searchBtn->getSize().y));

    deleteBtn->setPosition(sf::Vector2f(0,windowSize.y-1*deleteBtn->getSize().y));
    deleteFirstBtn->setPosition(sf::Vector2f(deleteBtn->getSize().x+10.f,windowSize.y-1*deleteFirstBtn->getSize().y));
    deleteLastBtn->setPosition(sf::Vector2f(2*deleteBtn->getSize().x+10.f,windowSize.y-1*deleteLastBtn->getSize().y));
    deleteMiddleBtn->setPosition(sf::Vector2f(3*deleteBtn->getSize().x+10.f,windowSize.y-1*deleteMiddleBtn->getSize().y));
}

SLL::~SLL()
{
    delete createBtn;
    delete emptyBtn;
    delete randomBtn;
    delete loadFromFileBtn;

    delete insertBtn;
    delete insertFrontBtn;
    delete insertBackBtn;
    delete insertMiddleBtn;

    delete updateBtn;

    delete searchBtn;

    delete deleteBtn;
    delete deleteFirstBtn;
    delete deleteLastBtn;
    delete deleteMiddleBtn;

    for(Node *node : deletedNode) delete node;
    for(Arrow *arrow : deletedArrow) delete arrow;
}

void SLL::empty()
{
    listNode.clear();
    listArrow.clear();
}

void SLL::loadFromFile(std::string path)
{
    empty();

    std::ifstream fi(path);
    if(!fi.is_open()) return;
    int val;
    while(fi>>val){
        assert(0<=val && val<=99);
        if(listNode.size()==10) break;
        listNode.pushBack(Node(val));
    }
    fi.close();
}

void SLL::randomList(int n)
{
    empty();
    while(n--)
        listNode.pushBack(Node(getRand(0,99)));
}

void SLL::makeList()
{
    if(listNode.empty()) return;

    ListElement<Node>* node=listNode.begin();
    node->data.position=START_POSITION;
    for(node=node->next; node!=listNode.end(); node=node->next){
        node->data.position=node->prev->data.position+sf::Vector2f(DISTANCE, 0);
        listArrow.pushBack(Arrow(&node->prev->data, &node->data));
    }

    // add new steps
    graph.addStep(0.5*FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    
    // draw arrows to graph
    graph.drawGrow(&listArrow,Colors::BLACK);
}

void SLL::insertWhenEmpty(int value)
{
    if(!listNode.empty()) return;

    listNode.pushBack(value);
    listNode.begin()->data.position=START_POSITION;

    // add new steps
    graph.addStep(0.5*FPS);

    // draw nodes to graph
    graph.drawGrow(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
}

void SLL::insertFront(int value)
{
    if(listNode.empty()){ 
        insertWhenEmpty(value);
        return;
    }

    listNode.pushFront(value);
    listArrow.pushFront(Arrow(&listNode.begin()->data, &listNode.begin()->next->data));
    listNode.begin()->data.position=START_POSITION+sf::Vector2f(0, DISTANCE);

    // step 1: draw new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->next->data,"head",Colors::RED);
    graph.draw(&listArrow,1,listNode.size()-1,Colors::BLACK);
    graph.drawGrow(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawSubscript(&listNode.begin()->data,"vtx",Colors::RED);
    //

    // step 2: draw new arrow
    graph.addStep(0.5*FPS);

    graph.draw(&listNode,1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->next->data,"head",Colors::RED);
    graph.draw(&listArrow,1,listNode.size()-1,Colors::BLACK);
    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawSubscript(&listNode.begin()->data,"vtx",Colors::RED);
    graph.drawGrow(&listArrow.begin()->data,Colors::ORANGE);
    //

    // step 3: assign head to new node
    graph.addStep(0.5*FPS);

    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);    
    graph.drawSubscript(&listNode.begin()->data,"head/vtx",Colors::RED);
    graph.drawFadeIn(&listNode.begin()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeOut(&listArrow.begin()->data,Colors::ORANGE);
    //

    // step 4: move new node to correct position
    graph.addStep(0.5*FPS);

    graph.drawMove(&listNode,1,listNode.size()-1,sf::Vector2f(DISTANCE, 0),Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head/vtx",Colors::RED);
    graph.drawMove(&listNode.begin()->data,START_POSITION-listNode.begin()->data.position,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listArrow,Colors::BLACK);
    //
}

void SLL::insertBack(int value)
{
    if(listNode.empty()){ 
        insertWhenEmpty(value);
        return;
    }

    listNode.pushBack(value);
    listArrow.pushBack(Arrow(&listNode.rbegin()->prev->data, &listNode.rbegin()->data));
    listNode.rbegin()->data.position=START_POSITION+sf::Vector2f(DISTANCE*(listNode.size()-1), 0);

    const int n=listNode.size();

    // step 1: traverse from head to tail
    for(int i=0; i<n-1; i++){
        // substep 1
        graph.addStep(0.5*FPS);

        if(i==0)
            graph.drawSubscript(&listNode.begin()->data,"head/tail",Colors::RED);
        else{
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,"tail",Colors::RED);
        }
        graph.draw(&listNode,0,i-1,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i,n-2,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeIn(&listNode.begin()->getNext(i)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,listArrow.size()-2,Colors::BLACK);
        //

        // substep 2
        if(i<n-2){
            graph.addStep(0.5*FPS);

            if(i==0)
                graph.drawSubscript(&listNode.begin()->data,"head/tail",Colors::RED);
            else{
                graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
                graph.drawSubscript(&listNode.begin()->getNext(i)->data,"tail",Colors::RED);
            }
            graph.draw(&listNode,0,i,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
            graph.draw(&listNode.begin()->getNext(i)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
            graph.draw(&listNode,i+1,n-2,Colors::WHITE,Colors::BLACK,Colors::BLACK);
            graph.draw(&listArrow,0,i-1,Colors::ORANGE);
            graph.draw(&listArrow,i,listArrow.size()-2,Colors::BLACK);
            graph.drawGrow(&listArrow.begin()->getNext(i)->data,Colors::ORANGE);
        }
        //
    }
    //

    // step 2: draw new node
    graph.addStep(0.5*FPS);

    if(n==2)
        graph.drawSubscript(&listNode.begin()->data,"head/tail",Colors::RED);
    else{
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.rbegin()->prev->data,"tail",Colors::RED);
    }
    graph.drawSubscript(&listNode.rbegin()->data,"vtx",Colors::RED);
    graph.draw(&listNode,0,n-3,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,n-2,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listArrow,0,listArrow.size()-2,Colors::ORANGE);
    graph.drawGrow(&listNode.rbegin()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    //

    // step 3: draw new arrow
    graph.addStep(0.5*FPS);

    if(n==2)
        graph.drawSubscript(&listNode.begin()->data,"head/tail",Colors::RED);
    else{
        graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        graph.drawSubscript(&listNode.rbegin()->prev->data,"tail",Colors::RED);
    }
    graph.drawSubscript(&listNode.rbegin()->data,"vtx",Colors::RED);
    graph.draw(&listNode,0,n-3,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,n-2,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listArrow,0,listArrow.size()-2,Colors::ORANGE);
    graph.draw(&listNode.rbegin()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawGrow(&listArrow.rbegin()->data,Colors::ORANGE);
    //

    // step 4: assign tail->next=newNode
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.rbegin()->data,"tail/vtx",Colors::RED);
    graph.draw(&listNode,0,n-2,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawFadeOut(&listNode,0,n-3,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.drawFadeOut(&listNode,n-2,n-2,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeOut(&listArrow,0,listArrow.size()-1,Colors::ORANGE);
    graph.draw(&listNode.rbegin()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    //
}

void SLL::insertMiddle(int value, int pos)
{
    if(pos<0 || pos>listNode.size()){
        std::cout << "Invalid position!" << std::endl;
        return;
    }
    if(pos==0){
        insertFront(value);
        return;
    }
    if(pos==listNode.size()){
        insertBack(value);
        return;
    }

    listNode.insert(value,pos);
    listNode.begin()->getNext(pos)->data.position=START_POSITION+sf::Vector2f(DISTANCE*pos, DISTANCE);
    listArrow.insert(Arrow(&listNode.begin()->getNext(pos)->data, &listNode.begin()->getNext(pos+1)->data),pos);
    listArrow.begin()->getNext(pos-1)->data.dest=&listNode.begin()->getNext(pos)->data;
    tmpNode.position=listNode.begin()->getNext(pos+1)->data.position;
    tmpArrow.src=&listNode.begin()->getNext(pos-1)->data;
    tmpArrow.dest=&tmpNode;

    // step 1: traverse to node at 'pos+1'
    for(int i=0; i<pos; i++){
        // substep 1: draw node at i
        graph.addStep(0.5*FPS);

        for(int j=1; j<=i; j++)
            graph.drawSubscript(&listNode.begin()->getNext(j)->data,std::to_string(j)+"/pre",Colors::RED);
        if(i){
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",Colors::RED);
        }
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",Colors::RED);
        graph.draw(&listNode,0,i-1,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listNode,pos+1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,pos-2,Colors::BLACK);
        graph.draw(&tmpArrow,Colors::BLACK);
        graph.draw(&listArrow,pos+1,listArrow.size()-1,Colors::BLACK);
        graph.drawFadeIn(&listNode.begin()->getNext(i)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        //

        // substep 2: draw arrow at i
        graph.addStep(0.5*FPS);

        for(int j=1; j<=i; j++)
            graph.drawSubscript(&listNode.begin()->getNext(j)->data,std::to_string(j)+"/pre",Colors::RED);
        if(i)
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
        else
            graph.drawSubscript(&listNode.begin()->data,"0/head/pre",Colors::RED);
        graph.draw(&listNode,0,i-1,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listNode,i+1,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listNode,pos+1,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,0,i-1,Colors::ORANGE);
        graph.draw(&listArrow,i,pos-2,Colors::BLACK);
        graph.draw(&tmpArrow,Colors::BLACK);
        graph.draw(&listArrow,pos+1,listArrow.size()-1,Colors::BLACK);
        if(i<pos-1)
            graph.drawGrow(&listArrow,i,Colors::ORANGE);
        else{
            graph.drawGrow(&tmpArrow,Colors::ORANGE);
            graph.drawFadeIn(&listNode.begin()->getNext(pos+1)->data,Colors::BLUE,Colors::BLUE,Colors::WHITE);
        }
        //
    }

    // step 2: draw new node
    graph.addStep(0.5*FPS);

    for(int i=1; i<pos; i++)
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",Colors::RED);
    if(pos+1<listNode.size()-1){
        graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",Colors::RED);
    }
    else
        graph.drawSubscript(&listNode.rbegin()->data,std::to_string(pos)+"/aft",Colors::RED);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,"vtx",Colors::RED);
    graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawGrow(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listNode,pos+1,Colors::BLUE,Colors::BLUE,Colors::WHITE);
    graph.draw(&listNode,pos+2,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,0,pos-2,Colors::ORANGE);
    graph.draw(&tmpArrow,Colors::ORANGE);
    graph.draw(&listArrow,pos+1,listArrow.size()-1,Colors::BLACK);
    //
    
    // step 3: draw new arrow
    graph.addStep(0.5*FPS);

    for(int i=1; i<pos; i++)
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",Colors::RED);
    if(pos+1<listNode.size()-1){
        graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos)+"/aft",Colors::RED);
    }
    else
        graph.drawSubscript(&listNode.rbegin()->data,std::to_string(pos)+"/aft",Colors::RED);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,"vtx",Colors::RED);
    graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listNode,pos+1,Colors::BLUE,Colors::BLUE,Colors::WHITE);
    graph.draw(&listNode,pos+2,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,0,pos-2,Colors::ORANGE);
    graph.draw(&tmpArrow,Colors::ORANGE);
    graph.drawGrow(&listArrow.begin()->getNext(pos)->data,Colors::GREEN);
    graph.draw(&listArrow,pos+1,listArrow.size()-1,Colors::BLACK);
    //

    // step 4: move arrow from arrow[pos-1] to arrow[pos]
    graph.addStep(0.5*FPS);

    for(int i=1; i<pos; i++)
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,std::to_string(i)+"/pre",Colors::RED);
    if(pos+1<listNode.size()-1){
        graph.drawSubscript(&listNode.begin()->getNext(pos+1)->data,std::to_string(pos+1)+"/aft",Colors::RED);
    }
    else
        graph.drawSubscript(&listNode.rbegin()->data,std::to_string(pos+1)+"/aft",Colors::RED);
    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/vtx",Colors::RED);
    graph.draw(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.draw(&listNode,pos-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.draw(&listNode,pos+1,Colors::BLUE,Colors::BLUE,Colors::WHITE);
    graph.draw(&listNode,pos+2,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawMove(&tmpNode,tmpNode.position,listNode.begin()->getNext(pos)->data.position,Colors::BLANK,Colors::BLANK,Colors::BLANK);
    graph.draw(&listArrow,0,pos-2,Colors::ORANGE);
    graph.draw(&tmpArrow,Colors::ORANGE);
    graph.draw(&listArrow.begin()->getNext(pos)->data,Colors::GREEN);
    graph.draw(&listArrow,pos+1,listArrow.size()-1,Colors::BLACK);
    //

    // step 5: move new node to correct position
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
    graph.drawSubscript(&listNode.begin()->getNext(pos)->data,std::to_string(pos)+"/vtx",Colors::RED);
    graph.draw(&listNode,0,pos-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    {
        Node* node=&listNode.begin()->getNext(pos)->data;
        graph.drawMove(node,sf::Vector2f(0,-DISTANCE),Colors::GREEN,Colors::GREEN,Colors::WHITE);
    }
    graph.drawMove(&listNode,pos+1,listNode.size()-1,sf::Vector2f(DISTANCE,0),Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.drawFadeOut(&listNode,0,pos-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
    graph.drawFadeOut(&listNode.begin()->getNext(pos-1)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.drawFadeOut(&listNode.begin()->getNext(pos)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawFadeOut(&listNode.begin()->getNext(pos+1)->data,Colors::BLUE,Colors::BLUE,Colors::WHITE);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeOut(&listArrow,0,pos-2,Colors::ORANGE);
    graph.drawFadeOut(&listArrow.begin()->getNext(pos-1)->data,Colors::ORANGE);
    graph.drawFadeOut(&listArrow.begin()->getNext(pos)->data,Colors::GREEN);
    //
}

void SLL::deleteWhenSingle()
{
    if(listNode.size()==0) return;
    // step 1: delete head
    graph.addStep(0.5*FPS);

    graph.drawShrink(&listNode.begin()->data,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    //

    deletedNode.push_back(listNode.popFront());
}

void SLL::deleteFirst()
{
    int sz=listNode.size();
    if(sz<=1){
        deleteWhenSingle();
        return;
    }

    // step 1: assign temp=head
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.begin()->data,"head/temp",Colors::RED);
    graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    //

    // step 2: assign head to next node
    if(sz>1){
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->data,"temp",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",Colors::RED);
        graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,Colors::BLACK);
        graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext()->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.drawFadeIn(&listArrow.begin()->data,Colors::GREEN);
    }
    //

    // step 3: delete temp
    if(sz>1){
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->data,"temp",Colors::RED);
        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",Colors::RED);
        graph.draw(&listNode,1,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.draw(&listNode,2,listNode.size()-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,1,listArrow.size()-1,Colors::BLACK);
        graph.drawShrink(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.drawShrink(&listArrow.begin()->data,Colors::GREEN);
    }
    else{
        graph.addStep(0.5*FPS);

        graph.drawShrink(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    }
    
    
    // step 4: move the rest of the list to the left
    if(sz>1){
        graph.addStep(0.5*FPS);

        graph.drawSubscript(&listNode.begin()->getNext()->data,"head",Colors::RED);
        graph.drawMove(&listNode,1,sf::Vector2f(-DISTANCE,0),Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.drawMove(&listNode,2,listNode.size()-1,sf::Vector2f(-DISTANCE,0),Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,1,listArrow.size()-1,Colors::BLACK);
    }
    

    deletedNode.push_back(listNode.popFront());
    deletedArrow.push_back(listArrow.popFront());
}

void SLL::deleteLast()
{
    int sz=listNode.size();
    if(sz<=1){
        deleteWhenSingle();
        return;
    }

    const int n=listNode.size();

    // step 1: assign pre=head
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
    graph.draw(&listNode,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    //

    // step 2: 
    graph.addStep(0.5*FPS);

    graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
    graph.drawSubscript(&listNode.begin()->next->data,"tail",Colors::RED);
    graph.draw(&listNode.begin()->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
    graph.draw(&listNode,1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
    graph.draw(&listArrow,Colors::BLACK);
    graph.drawFadeIn(&listNode.begin()->next->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
    graph.drawGrow(&listArrow.begin()->data,Colors::ORANGE);
    //

    // step 3: traverse tail
    for(int i=1; i<n; i++){
        // substep 1
        graph.addStep(0.5*FPS);

        if(i==1)
            graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
        else{
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i-1)->data,"pre",Colors::RED);
        }
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,"tail",Colors::RED);
        graph.draw(&listNode,0,i-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listNode,i,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.draw(&listArrow,0,i-2,Colors::ORANGE);
        graph.draw(&listArrow.begin()->getNext(i-1)->data,Colors::GREEN);
        graph.drawFadeIn(&listArrow.begin()->getNext(i-1)->data,Colors::BLACK);
        graph.draw(&listArrow,i,listArrow.size()-1,Colors::BLACK);
        //
        // substep 2
        graph.addStep(0.5*FPS);

        if(i==1)
            graph.drawSubscript(&listNode.begin()->data,"head/pre",Colors::RED);
        else{
            graph.drawSubscript(&listNode.begin()->data,"head",Colors::RED);
            graph.drawSubscript(&listNode.begin()->getNext(i-1)->data,"pre",Colors::RED);
        }
        graph.drawSubscript(&listNode.begin()->getNext(i)->data,"tail",Colors::RED);
        graph.draw(&listNode,0,i-2,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i-1,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext(i-1)->data,Colors::WHITE,Colors::ORANGE,Colors::ORANGE);
        graph.draw(&listNode,i,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.drawFadeIn(&listNode.begin()->getNext(i)->data,Colors::ORANGE,Colors::ORANGE,Colors::WHITE);
        graph.draw(&listNode,i+1,n-1,Colors::WHITE,Colors::BLACK,Colors::BLACK);
        graph.drawFadeIn(&listNode.begin()->getNext(i+1)->data,Colors::GREEN,Colors::GREEN,Colors::WHITE);
        graph.draw(&listArrow,0,i-2,Colors::ORANGE);
        graph.draw(&listArrow,i-1,listArrow.size()-1,Colors::BLACK);
        graph.drawGrow(&listArrow.begin()->getNext(i-1)->data,Colors::ORANGE);
        graph.drawGrow(&listArrow.begin()->getNext(i)->data,Colors::GREEN);
        //
    }
}

void SLL::processInput()
{
    sf::Event event;
    while(window->pollEvent(event))
        switch (event.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::LostFocus:
                isPause=true;
                window->setFramerateLimit(1);
                break;
            case sf::Event::GainedFocus:
                isPause=false;
                window->setFramerateLimit(FPS);
                break;
            case sf::Event::MouseButtonReleased:
                if(createBtn->isMouseOver(window)){
                    curBtn=Button::CREATE;
                }
                    else if(curBtn==Button::CREATE && emptyBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        empty();
                        curBtn=Button::NONE;
                    }
                    else if(curBtn==Button::CREATE && randomBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        randomList(getRand(0,10));
                        makeList();
                        curBtn=Button::NONE;
                    }
                    else if(curBtn==Button::CREATE && loadFromFileBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        loadFromFile("inp.txt");
                        makeList();
                        curBtn=Button::NONE;
                    }
                else if(insertBtn->isMouseOver(window)){
                    curBtn=Button::INSERT;
                }
                    else if(curBtn==Button::INSERT && insertFrontBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        insertFront(getRand(0,99));
                        curBtn=Button::NONE;
                    }
                    else if(curBtn==Button::INSERT && insertBackBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        insertBack(getRand(0,99));
                        curBtn=Button::NONE;
                    }
                    else if(curBtn==Button::INSERT && insertMiddleBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        insertMiddle(getRand(0,99),getRand(1,listNode.size()-1));
                        curBtn=Button::NONE;
                    }
                else if(updateBtn->isMouseOver(window)){
                    curBtn=Button::UPDATE;
                }
                else if(searchBtn->isMouseOver(window)){
                    curBtn=Button::SEARCH;
                }
                else if(deleteBtn->isMouseOver(window)){
                    curBtn=Button::DELETE;
                }
                    else if (curBtn==Button::DELETE && deleteFirstBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        deleteFirst();
                        curBtn=Button::NONE;
                    }
                    else if (curBtn==Button::DELETE && deleteLastBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        deleteLast();
                        curBtn=Button::NONE;
                    }
                    else if (curBtn==Button::DELETE && deleteMiddleBtn->isMouseOver(window)){
                        graph.finishAllSteps();
                        curBtn=Button::NONE;
                    }
                break;           
        }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !isPause)
        graph.nextStep();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !isPause)
        graph.prevStep();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        graph.setVisualType(STEP_BY_STEP);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        graph.setVisualType(AUTO);

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

void SLL::render()
{
    window->clear(Colors::WHITE);

    window->draw(*bg);

    window->draw(*createBtn);
    if(curBtn==Button::CREATE){
        window->draw(*emptyBtn);
        window->draw(*randomBtn);
        window->draw(*loadFromFileBtn);
    }

    window->draw(*insertBtn);
    if(curBtn==Button::INSERT){
        window->draw(*insertFrontBtn);
        window->draw(*insertBackBtn);
        window->draw(*insertMiddleBtn);
    }

    window->draw(*updateBtn);

    window->draw(*searchBtn);

    window->draw(*deleteBtn);
    if(curBtn==Button::DELETE){
        window->draw(*deleteFirstBtn);
        window->draw(*deleteLastBtn);
        window->draw(*deleteMiddleBtn);
    }

    graph.draw();

    window->display();
}

void SLL::run()
{
    randomList(4);
    makeList();
    while(window->isOpen()){
        processInput();
        render();
    }
}
