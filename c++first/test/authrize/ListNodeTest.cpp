#include <iostream>
#include <set>
#include <vector>
using namespace std;
class ListNodeTest
{
private:
    /* data */
    int val;
    //  一定要初始化
    ListNodeTest *next = NULL;
public:
    ListNodeTest(/* args */);
    ~ListNodeTest();
    void setVal(int val);
    int getVal();
    void setNext(ListNodeTest *next);

    ListNodeTest* getNext();

    ListNodeTest* reverseList(ListNodeTest* head);
    ListNodeTest* reverseBetween(ListNodeTest* head,int m, int n);  
    ListNodeTest(int x) :val(x),next(NULL){} ;
    ListNodeTest* getInterSextionNode(ListNodeTest* heada,ListNodeTest* headb);     

    int getListLenth(ListNodeTest *head);
    ListNodeTest *forwardLongList(int  long_len,int shoret_len,ListNodeTest *head);
    ListNodeTest* getInterSectionNode(ListNodeTest* heada,ListNodeTest* headb); 
    ListNodeTest* detectSycle(ListNodeTest* heada ); 

    ListNodeTest* detectSycleFastLow(ListNodeTest* heada ); 
    int minSubArrayLen(int target, vector<int> nums) {
        int len = INT_MAX;
        int n = nums.size(),sum =0;
        for (int left = 0,right =0; right < n; right++)
        {
            
            sum += nums[right];
            while (sum >= target)
            {
                 len = min(len,right-left+1);
                 sum -= nums[left++];
            }
            
             
        }
         return len == INT_MAX ? 0: len; 
    }
};

ListNodeTest::ListNodeTest(/* args */)
{
}

ListNodeTest::~ListNodeTest()
{
}


void ListNodeTest::setVal(int val){
    this->val = val;

}
int ListNodeTest::getVal(){
    return this->val;

}
void  ListNodeTest::setNext(ListNodeTest *next){
    this->next=next;

}

ListNodeTest*  ListNodeTest::getNext( ){
    return this->next;

}
//  链表取反
ListNodeTest*  ListNodeTest::reverseList( ListNodeTest* head){

     ListNodeTest*  new_head = NULL;
     while (head)
     {  
            ListNodeTest*  node = head->getNext();
            // new_head->setNext(node);
            head->setNext(new_head);
             new_head = head; // 更新 
            head = node; // 遍历链表
         
     }
    return new_head;
}

//  指定位置取反
ListNodeTest*  ListNodeTest::reverseBetween( ListNodeTest* head,int m ,int n){

     ListNodeTest*  pre_head = NULL;

     ListNodeTest*  result = head;
     int  change_len = n-m +1;

     while (head && --m)
     {  
            ListNodeTest*  node = head->getNext();
             pre_head = head;
             
            head = node; // 遍历链表
         
     }
    ListNodeTest*  modi_list_tail = head;
    ListNodeTest*  new_head = NULL;

    while (head && change_len)
    {
        ListNodeTest*  next = head->getNext();
        head->setNext(new_head);
        new_head = head;
        head = next;
        change_len--;
    }

    modi_list_tail->next = head;
    if (pre_head)
    
    {
        pre_head->setNext(new_head); 
    }else{
        result = new_head;
    }
    

    return result;
}


ListNodeTest*  ListNodeTest::getInterSextionNode(ListNodeTest* heada,ListNodeTest* headb){
    set<ListNodeTest*> node_set;
    while (heada)
    {
        /* code */
        node_set.insert(heada);

        heada = heada->getNext();
    }
    
    while (headb)
    {
         if(node_set.find(headb) != node_set.end()){
           return headb;
         }
          headb = headb->getNext();
    }

    return NULL;
}


int ListNodeTest::getListLenth(ListNodeTest *head){
    int len = 0 ;
    while (head)
    {
        /* code */
        len ++;
        head = head->getNext();
    }
    
}

ListNodeTest* ListNodeTest::forwardLongList(int  long_len,int shoret_len,ListNodeTest *head){
    int delta = long_len - shoret_len;
    while (head && delta)
    {
        /* code */

        head = head->getNext();
        delta--;
    }
    return head;
    

}

ListNodeTest* ListNodeTest::getInterSectionNode(ListNodeTest* heada,ListNodeTest* headb){
    int len_a = getListLenth(heada);
    int len_b = getListLenth(headb);
    if(len_a > len_b){
        heada = forwardLongList(len_a,len_b,heada);
    }else{
         headb = forwardLongList(len_b,len_a,headb);
    }

    while (heada && headb)
    {
        if(heada == headb){
            return heada;
        }
        heada = heada->getNext();
        headb= headb->getNext();
    }
    return  NULL;
}

ListNodeTest* ListNodeTest::detectSycle(ListNodeTest* heada){
    set<ListNodeTest*> node_set;
    while (heada)
    {
         if(node_set.find(heada) != node_set.end()){
            return heada;

         }
          node_set.insert(heada);

         heada = heada->getNext();
    }
    return NULL;
}

/**
 * 快慢指针 同一个循环遍历中一个指针执行两次移动
 */
ListNodeTest* ListNodeTest::detectSycleFastLow(ListNodeTest* heada){
    
     ListNodeTest *fast=heada;
     ListNodeTest *slow = heada;
      ListNodeTest *meet = NULL;

    while (fast)
    {
         slow = slow->getNext();
         fast = fast->getNext();

         if (!fast)
         {
            return NULL;
         }
         fast = fast->getNext();
         if (fast == slow)
         {
             meet =fast;
             break;
         }
    }
    if (meet == NULL)
        {
            return NULL;
        }

    while (heada && meet)   // 

     {
        if (heada == meet)
        {
            return heada; // head 和meet 相遇说明起始位置有环
        }
        heada = heada->getNext();
        meet = meet->getNext();
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    ListNodeTest a;
    ListNodeTest b;
    ListNodeTest c;
    ListNodeTest d;
    ListNodeTest e;

    a.setVal(1);
    b.setVal(2);
    c.setVal(3);
    d.setVal(4);
    e.setVal(5);
    a.setNext(&b);
    b.setNext(&c);
    c.setNext(&d);
    d.setNext(&e);

    ListNodeTest *head = &a; 
    while (head)
    {
        /* code */
         cout<< head->getVal()<<endl;
         head = head->getNext();
    }
    //  链表取反


     ListNodeTest  test;
     test.setNext(head);


    cout<< "=========================reverseBetween===================="<<endl;
    ListNodeTest *head3 = test.reverseBetween( &a ,1,3);
 
    ListNodeTest *head4 = head3;
    
     while (head3)
    {
      
         cout<< " head3: "<<head3->getVal()<<endl;
         head3 = head3->getNext();
    }

    cout<< "===========================reverseList=================="<<endl;
    ListNodeTest *head2 = test.reverseList( head4 );
      ListNodeTest *head5 = head2;
     while (head2)
    {
        /* code */
         cout<< head2->getVal()<<endl;
         head2 = head2->getNext();
    }



     set<ListNodeTest*> node_set;
    while (head5)
    {
        /* code */
        node_set.insert(head5);

        head5 = head5->getNext();
    }
    // int nums[] = {2,3,1,2,4,3};

    vector<int> nums = {2,3,1,2,4,3};
     
    int res = head2->minSubArrayLen(7, nums);
     cout<< "res =  "<<res <<endl;
    return 0;
}

