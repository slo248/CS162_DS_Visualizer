#ifndef CORE_CONTAINER_H
#define CORE_CONTAINER_H

namespace Core {
class Container {
   public:
    Container();
    virtual ~Container(){};

    virtual void init() = 0;
    virtual void clear() = 0;

    int size() const;
    bool empty() const;

   protected:
    int mSize;
};
}  // namespace Core

#endif  // CORE_CONTAINER_H
