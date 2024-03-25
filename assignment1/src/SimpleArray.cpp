#include "SimpleArray.h"


SimpleArray::SimpleArray(AllocationTracker* ptr)
    :mArray(ptr)
{
}

SimpleArray::~SimpleArray()
{
    delete [] this->mArray;
}

AllocationTracker*
SimpleArray::get() const
{
    return SimpleArray::mArray;
}

bool 
SimpleArray::isNonNull() const
{
    return SimpleArray::mArray != nullptr;
}

AllocationTracker&
SimpleArray::getReference(const uint32_t i) const
{
     return this->mArray[i];
}

AllocationTracker*
SimpleArray::release()
{
    AllocationTracker* newAT(nullptr);
    AllocationTracker* oldAT = this->mArray;
    this->mArray = newAT; 
    return oldAT;
}

void 
SimpleArray::reset(AllocationTracker* rhs)
{
    delete [] this->mArray;
    this->mArray = rhs;
}

void 
SimpleArray::swap(SimpleArray& rhs)
{
    std::swap(this->mArray,rhs.mArray);
}



