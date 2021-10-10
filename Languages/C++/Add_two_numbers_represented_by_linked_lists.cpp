class Solution
{
     public:
    struct Node* reverse(struct Node *head){
       Node* curr = head;
       Node* prev = NULL;
       
       while(curr != NULL){
           Node* next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
       }

       return prev;
   }
   //Function to add two numbers represented by linked list.
   struct Node* addTwoLists(struct Node* first, struct Node* second)
   {
       // code here
       Node* a = reverse(first);
       Node* b = reverse(second);
       
       Node* head = new Node(0);
       
       int carry = 0;
       Node* curr = head;
       
       while(a != NULL || b != NULL) {
           int x = (a == NULL) ? 0 : a->data;
           int y = (b == NULL) ? 0 : b->data;
           
           int sum = x + y + carry;
           carry = sum/10;
           sum %= 10;
           
           curr->next = new Node(sum);
           curr = curr->next;
           
           if(a != NULL) a = a->next;
           if(b != NULL) b = b->next;
       }
       
       if(carry)
       curr->next = new Node(carry);
           
       return reverse(head->next);
   }
};


