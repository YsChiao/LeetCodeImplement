/*
 * AddTwoNumbers, Problem No.2
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  vector<int> sum (const vector<int>& str1, const vector<int>& str2)
    {
        vector<int> result;
        int left_length = str1.size();
        int right_length = str2.size();
        int carry = 0;
        int data = 0;

        if (left_length <= right_length)
        {
            for (int i = 0; i < left_length; i++)
            {
                int temp = str1.at(i) + str2.at(i) + carry;
                data = temp % 10;

                if (temp >= 10)
                {
                    carry = 1;
                }
                else
                {
                    carry = 0;

                }
                result.push_back(data);
            }

            if (left_length == right_length)
            {
                if (1 == carry)
                {
                    result.push_back(1);
                }
                //std::reverse(result.begin(), result.end());
                return result;
            }
            else
            {
                for (int i = left_length; i < right_length; i++)
                {
                    int temp = str2.at(i) + carry;
                    data = temp % 10;

                    if (temp >= 10)
                    {
                        carry = 1;
                    }
                    else
                    {
                        carry = 0;

                    }
                    result.push_back(data);
                }
                if (1 == carry)
                {
                    result.push_back(1);
                }
                //std::reverse(result.begin(), result.end());
                return result;
            }
        }
        else
        {
            exit(1);
        }
    }



    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {

        ListNode* data1 = l1;
        ListNode* data2 = l2;
        vector<int> str1;
        vector<int> str2;
        vector<int> result;

        for (data1= l1; data1!= NULL; data1= data1->next)
        {
            str1.push_back(data1->val);
        }

        for (data2 = l2; data2!= NULL; data2 = data2->next)
        {
            str2.push_back(data2->val);
        }

        if (str1.size() <= str2.size())
            result = sum(str1, str2);
        else
            result = sum(str2, str1);


        ListNode* node = new ListNode(result.front());
        ListNode* head = node;

        for (size_t i = 1; i < result.size(); i++)
        {
            int digit = result.at(i);
            ListNode* temp = new ListNode(digit);
            node->next = temp;
            node = node->next;
        }

        return head;
    }
};

//int main ()
//{
//    ListNode* l1 = new ListNode(9);
//    ListNode* l2 = new ListNode(1);
//    ListNode* result;

//    ListNode* head1 = l1;
//    ListNode* head2 = l2;
//    for (size_t i = 0; i < 9; i++)
//    {
//        ListNode* temp = new ListNode(9);
//        l2->next = temp;
//        l2 = l2->next;
//    }


//    ListNode* f1 = head1;
//    while(f1!=NULL)
//    {
//        std::cout << f1->val << " ";
//        f1 = f1->next;
//    }
//    std::cout << std::endl;

//    ListNode* f2 = head2;
//    while(f2!=NULL)
//    {
//        std::cout << f2->val << " ";
//        f2 = f2->next;
//    }
//    std::cout << std::endl;



//    Solution solution;
//    result = solution.addTwoNumbers(head1, head2);

//    while(result!=NULL)
//    {
//        std::cout << result->val << " ";
//        result = result->next;
//    }
//    std::cout << std::endl;


//    std::system("PAUSE");
//    return 0;

//}
