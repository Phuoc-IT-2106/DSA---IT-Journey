#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
struct NODE{
        int data;
        NODE* next;
    };
    NODE* createNODE(int val){
        NODE* newNODE = new NODE;
        newNODE -> data = val;
        newNODE -> next = nullptr;
        return newNODE;
    }
class Solution{
    public:
    //CREATE LIST FROM ARRAY
    NODE* createList(vector<int>&a){
        int n = a.size();
        if(n == 0) return nullptr;
        NODE* head = createNODE(a[0]);
        NODE* current = head;
        for(int i = 1; i < n; i++){
            current->next = createNODE(a[i]);
            current = current->next;
        }
        return head;
    }
    //PRINT LIST
    void printList(NODE* head){
        NODE* current = head;
        while(current){
            cout << current->data;
        if(current->next){
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> nullptr " << endl; 
}
    //INSERT HEAD
    NODE* InsertHead(NODE* head, int val){
        NODE* newNODE = createNODE(val);
        newNODE -> next = head;
        return newNODE;
    }
    //INSERT TAIL
    NODE* InsertTail(NODE* head, int val){
        NODE* newNODE = createNODE(val);
        if(!head) return newNODE;
        NODE* current = head;
        while(current->next) current = current -> next;
        current->next = newNODE;
        return head;
    }
    NODE* DeleteHead(NODE* head){
        if(!head) return nullptr;
        NODE* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    NODE* DeleteTail(NODE* head){
        if(!head) return nullptr;
        if(!head->next) {
            delete head;
            return nullptr;
    }
        NODE* current = head;
        while(current->next->next) current = current-> next;
        delete current->next;
        current->next = nullptr;
        return head;
        }
    
        //DELETE FIRST VAL OF LIST
        NODE* DeleteFirstVal(NODE*head, int val){
            if(!head) return nullptr;
            if(head->data == val) return DeleteHead(head);
            NODE* current = head;
            while(current && current->next){
                if(current->next->data == val){
                    NODE* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return head;
                }
                current = current->next;
            }
            return head;
        }
      NODE*  InsertAtPos(NODE* head, int pos, int val){
            if(pos == 0){
                NODE* newNODE = InsertHead(head,val);
                return newNODE;
            }
            NODE* current = head;
            int i = 0; 
            while(current && i < pos - 1){
                current = current->next;
                i++;
            }
            if(!current || pos < i - 1){
                cout << "INVALID POS\n" ;
                return head;
            }
            NODE* newNODE = createNODE(val);
            newNODE -> next = current->next;
            current->next = newNODE;
            return head;
        }
        int CountOccurance(NODE* head, int target){
            if(!head) return 0;
            NODE* current = head;
            int count = 0;
            while(current){
                if(current->data == target)count++;
                current = current->next;
            }
            return count;
        }
        vector<int>PositionsOfTarget(NODE* head, int target){
            vector<int>result;
            if(!head) return {};
            int i = 0;
            NODE* current = head;
            while(current){
                if(current->data == target){
                    result.push_back(i);
                }
                current = current->next;
                i++;
            }
            return result;
        }
        NODE* DeleteAllTarget(NODE* head, int target){
            while(head && head->data == target) head = DeleteHead(head);
            if(!head) return nullptr;
            NODE* current = head;
            while(current && current->next){
                if(current->next->data == target){
                    NODE* temp = current->next;
                    current->next = temp->next;
                    delete temp;
                }
                else current = current->next;
            }
            return head;
        }
        NODE* RemoveDuplicates(NODE* head){
            if(!head || !head->next) return head;
            NODE* current = head;
            while(current){
                NODE* runner = current;
                while(runner && runner->next){
                    if(runner->next->data == current->data){
                        NODE* temp = runner->next;
                        runner->next = temp->next;
                        delete temp;
                    }
                    else{
                        runner = runner->next;
                    }
                }
                current = current->next;
            }
            return head;
        }

        //MERGE SORTED LISTS - https://leetcode.com/problems/merge-two-sorted-lists/description/
        NODE* MergetwoSortedList(NODE* head1, NODE* head2){
            NODE* dummy = createNODE(0);
            NODE* current = dummy;
            while(head1 && head2){
                if(head1->data <= head2->data){
                    current->next = head1;
                    current = current->next;
                    head1 = head1->next;
                }
                else{
                    current->next = head2;
                    current  = current->next;
                    head2 = head2->next;
                }
            }
            if(head1){
                current->next = head1;
            }
            if(head2){
                current->next = head2;
            }
            NODE* mergehead = dummy->next;
            delete dummy;
            return mergehead;
        }

        //https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=problem-list-v2&envId=linked-list
        NODE* DeleteAll_In_Array(NODE* head, vector<int>&a){
            unordered_set<int> to_remove;
            for(int i = 0; i < a.size(); i++){
                to_remove.insert(a[i]);
            }
            while(head && to_remove.count(head->data)){
                head = DeleteHead(head);
            }
            if(!head) return nullptr;
            NODE* current = head;
            while(current && current->next){
                if(to_remove.count(current->next->data)){
                    NODE* temp = current->next;
                    current->next = temp->next;
                    delete temp;
                }
                else current = current->next;
            }
            return head;
        }

        //REVERSE SINGLE LINKED LIST
        NODE* ReverseSingleList(NODE* head){
            if(!head || !head->next) return head;
            NODE* prev = nullptr;
            NODE* current = head;
            while(current){
                NODE* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            return prev;
        }

        //REVERSE LINKED LIST II - https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=problem-list-v2&envId=linked-list
    NODE* ReverseLeftToRight(NODE* head, int left, int right){
        if(!head || !head->next || left == right) return head;
        NODE* dummy = createNODE(0);
        dummy->next = head;
        NODE* prev = dummy;
        for(int i = 1; i < left; i++){
            prev = prev->next;
        }
        NODE* leftNODE = prev->next;
        NODE* rightNODE = leftNODE;
        for(int i = left; i < right; i++){
            rightNODE = rightNODE -> next;
        }
        NODE* afterRight = rightNODE->next;
        prev->next = nullptr;
        rightNODE->next = nullptr;
        NODE* reserved_head = ReverseSingleList(leftNODE);
        prev->next = reserved_head;
        leftNODE->next = afterRight;
        NODE* result = dummy->next;
        delete dummy;
        return result;
    }
};
int main(){
    Solution sol;
    vector<int>arr = {1,2,3,4,5};
    NODE* p = sol.createList(arr);
    //sol.printList(p);
    //cout << "LIST AFTER INSERT HEAD\n";
    NODE* p2 = sol.InsertHead(p,6);
    //sol.printList(p2);
    //cout << "LIST AFTER INSERT TAIL\n";
    NODE* p3 = sol.InsertTail(p2,7);
    //sol.printList(p3);
    //cout << "LIST AFTER DELETE HEAD\n ";
    NODE* p4 = sol.DeleteHead(p3);
    //sol.printList(p4);
    //cout << "LIST AFTER DELETE TAIL\n";
    NODE* p5 = sol.DeleteTail(p4);
    //sol.printList(p5);
    NODE* p6 = sol.DeleteFirstVal(p5,3);
    //sol.printList(p6);
    NODE* p7 = sol.InsertAtPos(p6,1,10);
    NODE* p8 = sol.InsertTail(p7,2);
    //sol.printList(p8);
    //cout << sol.CountOccurance(p8,2) << endl;
    //vector<int>result = sol.PositionsOfTarget(p8,2);
    //for(int i = 0; i < result.size(); i++){
       // cout << result[i] << " ";
    //}
    //NODE* p9 = sol.DeleteAllTarget(p8,2);
    //sol.printList(p9);
    NODE* p9 = sol.InsertTail(p8,10);
    NODE* p10 = sol.InsertHead(p9,1);
    //sol.printList(p10);
    NODE* p11 = sol.RemoveDuplicates(p10);
    //sol.printList(p11);
    vector<int> L1 = {1,3,5,7,9};
    vector<int> L2 = {2,4,6,8,10,12};
    NODE* head1 = sol.createList(L1);
    NODE* head2 = sol.createList(L2);
    //sol.printList(head1);
    //sol.printList(head2);
    //NODE* mergelist = sol.MergetwoSortedList(head1,head2);
    //sol.printList(p11);
    vector<int> arr2 = {1,2,3,4,5};
    vector<int> nums = {1,2,3};
    NODE* arr2_head = sol.createList(arr2);
    //NODE* new_arr2_head = sol.DeleteAll_In_Array(arr2_head,nums);
    sol.printList(arr2_head);
    NODE* reversed = sol.ReverseSingleList(arr2_head);
    sol.printList(reversed);
    return 0;
}