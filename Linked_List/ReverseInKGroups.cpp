// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

//k is a positive integer and is less than or equal to the length of the linked list. 
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// solution(good ques)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Recursive approach
    ListNode* reverse(ListNode* head,ListNode* node)
    {
        ListNode* prev=node;
        while(head!=node)
        {
            ListNode* curr=head->next;
            head->next=prev;
            prev=head;
            head=curr;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node=head;
        for (int i=0;i<k;i++)
        {
            if(!node)
                return head;
            node=node->next;
        }
        ListNode* new_head=reverse(head,node);
        head->next=reverseKGroup(node,k);
        return new_head;
    }

// Iterative approach
 ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        while(temp)
        {
            temp=temp->next;
            count++;
        }
        count=count/k;
        ListNode* ans=new ListNode(-1);
        ListNode* newhead=ans;
        while(count--)
        {
            ListNode* currhead=head;
            int x=k;
            ListNode* prev=NULL;
            while(x--)
            {
                ListNode* curr=head->next;
                head->next=prev;
                prev=head;
                head=curr;
            }
            x=k;
            newhead->next=prev;
            newhead=currhead;
        }
        newhead->next=head;
        return ans->next;
    }