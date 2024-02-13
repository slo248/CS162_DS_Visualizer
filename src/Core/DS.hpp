#ifndef DS_HPP
#define DS_HPP

#include "stdexcept"

namespace Core {
class DS {
   public:
    DS() : mSize(0){};
    virtual ~DS() { mSize = 0; };
    // virtual void clear() = 0;
    size_t size() const { return mSize; };
    bool empty() const { return !mSize; };

   protected:
    size_t mSize;
};
}  // namespace Core

#endif  // DS_HPP
