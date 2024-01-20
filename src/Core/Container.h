#ifndef CORE_CONTAINER_H
#define CORE_CONTAINER_H

class Container {
   public:
    Container();
    virtual ~Container();

    virtual Container& init() = 0;
    virtual Container& clear() = 0;

    int size() const;
    bool empty() const;

   protected:
    int mSize;
};

#endif  // CORE_CONTAINER_H
