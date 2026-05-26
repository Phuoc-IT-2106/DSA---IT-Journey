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
        newNODE->data = val;
        newNODE->next = nullptr;
        return newNODE;
    }
class Solution{
    public:
    
    NODE* createFromList(vector<int>&a){
        int n = a.size();
        if(n == 0) return nullptr;
        NODE* head = createNODE(a[0]);
        NODE* current = head;
        for(int i = 1; i < n; i++){
                NODE* temp = createNODE(a[i]);
                current->next = temp;
                current = current->next;
            }
        
        return head;
    }
    void printList(NODE* head){
        NODE* current = head;
        while(current){
            cout << current->data << " " << " -> ";
            if(!current->next) cout << " " << "nullptr";
            current = current->next;
        }
    }
    NODE* InsertHead(NODE* head, int val){
        NODE* newHead = createNODE(val);
        if(!head) return newHead;
        newHead -> next = head;
        return newHead;
    }
    NODE* InsertTail(NODE* head, int val){
        NODE* newTail = createNODE(val);
        if(!head) return newTail;
        NODE* current = head;
        while(current->next){
            current = current->next;
        }
        current->next = newTail;
        newTail->next = nullptr;
        return head;
    }
    NODE* DeleteHead(NODE* head){
        if(!head) return nullptr;
        if(head && !head->next){
            delete head;
            return nullptr;
        }
        NODE* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    NODE* DeleteTail(NODE* head){
        if(!head) return nullptr;
        if(head && !head->next){
            delete head;
            return nullptr;
        }
        NODE* current = head;
        while(current->next->next){
            current = current->next;
        }
        NODE* temp = current->next;
        current->next = temp->next;
        delete temp;
        return head;
    }
    NODE* DeleteAtPos(NODE* head, int pos){
        if(!head || pos < 0) return nullptr;
        if(head && pos == 0 ){
            head = DeleteHead(head);
            return head;
        }
        int i = 0;
        NODE* current = head;
        while(current->next && i < pos - 1){
            current = current->next;
            i++;
        }
        if(current){
            NODE* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        return head;
    }

    NODE* InsertAfterPos(NODE* head, int pos, int val){
        if(pos < 0) return head;
        if(!head || pos == 0){
            head = InsertHead(head,val);
            return head;
        }
        NODE* current = head;
        int i = 0;
        while(current->next && i < pos - 1){
            current = current->next;
            i++;
        }
        if(!current || i < pos - 1){
            cout << "INVALID POS" << endl;
            return head;
        }
        NODE* newNODE = createNODE(val);
        newNODE->next = current->next;
        current->next = newNODE;
        return head;
    }
    NODE* DeleteFirstTarget(NODE* head, int target){
        if(!head) return nullptr;
        if(head && head->data == target){
            head = DeleteHead(head);
            return head;
        }
        NODE* current = head;
        while(current && current->next){
            if(current->next->data == target){
                NODE* temp = current->next;
                current->next = temp->next;
                delete temp;
                return head;
            }
            else current = current->next;
        }
        cout << "TARGET NOT IN THE LIST\n";
        return head;
    }

    NODE* DeleteAllTargets(NODE* head, int target){
        while(head && head->data == target){
            head = DeleteHead(head);
        }
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
                else runner = runner->next;
            }
            current = current->next;
        }
        return head;
    }

    NODE* MergeSortedLists(NODE* head1,NODE* head2){
        if(!head1 || !head2) return nullptr;
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
                current = current->next;
                head2 = head2->next;
            }
        }
        if(head1){
            current->next = head1;
        }
        if(head2){
            current->next = head2;
        }
        NODE* newHead = dummy->next;
        delete dummy;
        return newHead;
    }

    NODE* RemoveNodesInArray(NODE* head, vector<int>& nums){
        int n = nums.size();
        if(n == 0) return nullptr;
        unordered_set<int> toRemove;
        for(int i = 0; i < n; i++) toRemove.insert(nums[i]);
        while(head && toRemove.count(head->data)){
            head = DeleteHead(head);
        }
        if(!head) return nullptr;
        NODE* current = head;
        while(current && current->next){
            if(toRemove.count(current->next->data)){
                NODE* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            else current = current->next;
        }
        return head;
    }

    NODE* ReverseList(NODE* head){
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

    NODE* ReverseBetween(NODE* head, int left, int right){
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
            rightNODE = rightNODE->next;
        }
        NODE* afterRight = rightNODE->next;
        prev->next = nullptr;
        rightNODE->next = nullptr;
        NODE* reverserd_head = ReverseList(leftNODE);
        prev->next = reverserd_head;
        leftNODE->next = afterRight;
        NODE* result = dummy->next;
        delete dummy;
        return result;

    }
};



int main(){
    Solution Sol;
    vector<int>arr = {1,2,3,4,5};
    vector<int>arr2 = {6,7,8,9,10};
    NODE* p1 = Sol.createFromList(arr);
    //NODE* p3 = Sol.createFromList(arr2);
    //NODE* p2 = Sol.InsertHead(p1,6);
    //NODE* p3 = Sol.InsertTail(p2,7);
    //NODE* p2 = Sol.DeleteTail(p1);
    //NODE* p2 = Sol.DeleteAtPos(p1,2);
    //NODE* p2 = Sol.InsertAfterPos(p1,0,6);
    //NODE* p2 = Sol.DeleteFirstTarget(p1,100);
    //NODE* p2 = Sol.DeleteAllTargets(p1,2);
    //NODE* p2 = Sol.RemoveDuplicates(p1);
    //NODE* newhead = Sol.MergeSortedLists(p1,p3);
    vector<int>nums = {5};
    //NODE* p2 = Sol.RemoveNodesInArray(p1,nums);
    NODE* p2 = Sol.ReverseBetween(p1,2,4);
    Sol.printList(p2);

}