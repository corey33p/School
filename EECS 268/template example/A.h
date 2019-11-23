#ifndef _A
#define _A

template<class ItemType>
class A {
    private:
        ItemType item;
    public:
        A();
        A(ItemType& anItem);
        ItemType getItem() const;
};

#endif
