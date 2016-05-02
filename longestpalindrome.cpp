/*
 * Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000,
 * and there exists one unique longest palindromic substring.
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


// Time Limit Exceeded
//class Solution
//{
//public:
//    string longestPalindrome(string s)
//    {
//        size_t start = 0;
//        size_t pos = start + 1;
//        string substr;
//        substr = s.at(start);
//        string str;
//        string longstr;

//        if (1 == s.length())
//        {
//            return s;
//        }
//        else
//        {
//            while (pos != s.length())
//            {
//                if (s.at(pos) != s.at(start))
//                {
//                    substr += s.at(pos);
//                    std::cout << "1: " <<substr << std::endl;
//                    pos++;
//                    if (s.length() == pos)
//                    {
//                        substr.clear();
//                        start++;
//                        substr += s.at(start);
//                        pos = start + 1;
//                    }
//                }
//                else
//                {
//                    substr += s.at(pos);
//                    std::cout << "2: " <<substr << std::endl;
//                    bool check = std::equal(substr.begin(), substr.begin() + substr.length()/2, substr.rbegin());
//                    if (check)
//                    {
//                        if (10000 == substr.length())
//                        {
//                            return substr;
//                        }
//                        else
//                        {
//                            str = substr;
//                            while(pos!=s.length()-1)
//                            {
//                                pos++;
//                                substr += s.at(pos);
//                                std::cout << "3: " << substr << std::endl;
//                                bool check = std::equal(substr.begin(), substr.begin() + substr.length()/2, substr.rbegin());
//                                if (check)
//                                {
//                                    str = substr;
//                                }

//                            }
//                            if (str.length() > longstr.length())
//                            {
//                                longstr = str;
//                                string leftstr = s.substr(start+1);
//                                if (longstr.length() >= leftstr.length())
//                                {
//                                    return longstr;
//                                }
//                            }

//                        }
//                        substr.clear();
//                        start++;
//                        substr += s.at(start);
//                        pos = start + 1;
//                    }
//                    else
//                    {
//                        substr.clear();
//                        start++;
//                        substr += s.at(start);
//                        pos = start + 1;
//                    }
//                }
//            }

//        }
//        return longstr;

//    }
//};


/*
 *
 * [解题思路]
 * O(n*n)。对于每一个字符，以之作为中间元素往左右寻找。注意处理奇偶两种模式：
 * 1. aba
 * 2. abba
*/


class Solution
{
public:
    string longestPalindrome(string s)
    {
        int left;
        int right;
        string substr;
        string substr1;
        string substr2;
        string str;

        if (1 == s.length())
        {
            str = s.at(0);
            return str;
        }

        for (size_t i = 0; i < s.length() - 1; i++)
        {
            if (s.at(i) == s.at(i+1))
            {
                left = i;
                right = i+1;
                substr1 = find(left, right, s);
            }
            if (substr1.length() > str.length())
            {
                str = substr1;
            }

            left = i;
            right = i;
            substr2 = find(left, right, s);

            if (substr2.length() > str.length())
            {
                str = substr2;
            }
        }
        return str;
    }


    string find (int left, int right, string s)
    {
        string str;
        int step = 1;
        int length = s.length();
        if (left == right)
        {
            str = s.at(left);
        }
        else
        {
            str = s.at(left);
            str += s.at(right);
        }

        while ((left-step) >= 0 && (right+step) < length)
        {
            if(s.at(left-step) == s.at(right+step))
            {
                step++;
            }
            else
            {
                break;
            }
        }

        step--;
        str = s.substr(left-step, right-left+2*step+1);
        return str;
    }
};



//int main ()
//{
//    string a = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
//    //string a = "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg";
//    //string a = "dbaabbaacdef";
//    //string a = "baaaabcaaa";
//    //string a = "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//    string result;

//    Solution s;
//    result = s.longestPalindrome(a);
//    std::cout << "result: " << result << std::endl;
//    std::cout << "result length: " << result.length() << std::endl;
//    std::system("pause");
//    return 0;
//}
