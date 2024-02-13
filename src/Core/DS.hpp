#ifndef DS_HPP
#define DS_HPP

namespace Core {
class DS {
   public:
    DS() : mSize(0){};
    virtual ~DS() { mSize = 0; };
    virtual void init() = 0;
    virtual void clear() = 0;
    int size() const { return mSize; };
    bool empty() const { return !mSize; };

   protected:
    int mSize;
};
}  // namespace Core

#endif  // DS_HPP
