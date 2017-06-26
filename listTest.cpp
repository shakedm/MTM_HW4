#include "list.h"
#include "mtmtest.h"
#include "Exceptions.h"


static void LISTbasic(){
    List <int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4,list.end());

    item=1;
    for (List<int>::Iterator it= list.begin(); it != list.end(); ++it) {
        ASSERT_EQUALS(item++, *it);

    }
    ASSERT_EQUALS(4,list.getSize());
    List<int>

}


