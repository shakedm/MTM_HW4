#include "../list.h"
#include "../mtmtest.h"
#include "../Exceptions.h"
class Equal {
private:
    int target;
public:
    Equal(int i) : target(i) {}
    bool operator()(const int& i) const {
        return i == target;
    }
};

static void LISTbasic(){
    List <int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4,list.end());

    int item=1;
    for (List<int>::Iterator it= list.begin(); it != list.end(); ++it) {
        ASSERT_EQUALS(item++, *it);

    }
    ASSERT_EQUALS(4,list.getSize());
    List<int>::Iterator it =list.begin();
    list.remove(++it);
    ASSERT_EQUALS(list.getSize(),3);
    it=list.begin();
    ASSERT_EQUALS(1,*it);

}

static void LISToperators(){
    List<double> list;
    list.insert(1.5);
    list.insert(2.2,list.begin());
    for (int i = 10; i <15 ; ++i) {
        list.insert(i);

    }
    List<double>::Iterator it= list.begin();
    ASSERT_EQUALS(*it,2.2);
    it++;
    ASSERT_EQUALS(*it,1.5);
    ++it;
    ASSERT_EQUALS(*it,10);
    --it;
    ASSERT_EQUALS(*it,1.5);
    it--;
    ASSERT_EQUALS(*it,2.2);
    List<double >::Iterator iterator1= list.begin();
    ASSERT_TRUE(it==iterator1);
    it=list.end();
    ASSERT_FALSE(it==iterator1);
    ASSERT_TRUE(it!=iterator1);
}
static void LISTfind(){
    List<int> list;
    for (int i = 0; i <10 ; ++i) {
        list.insert(i);
    }
    ASSERT_EQUALS(list.end(),list.find(Equal(20)));
    ASSERT_NOT_EQUAL(list.begin(),list.find(Equal(2)));

}

int mainList(){
    RUN_TEST(LISTfind);
    RUN_TEST(LISToperators);
    RUN_TEST(LISTbasic);
    return 0;
}
