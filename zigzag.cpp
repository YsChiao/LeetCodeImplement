/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 *
 *
 * brute force.
*/

#include <iostream>
#include <string>

using namespace std;


class Solution
{
public:
    string convert(string s, int numRows)
    {
        int length = s.length();
        if (1 == numRows)
        {
            return s;
        }
        else if (2 == numRows)
        {
            string odd;
            string even;
            for (int i =0; i < length; i++)
            {
                if (0 == i%2)
                {
                    even += s.at(i);
                }
                else
                {
                    odd += s.at(i);
                }
            }
            return even+odd;
        }
        else
        {
            int block = 2*numRows - 2;
            int middle = numRows - 2;
            int straight = 0;
            int hypotenuse = 0 ;

            straight = length / block;
            if (0 == length%block)
            {
                hypotenuse = straight;
            }
            else
            {
                hypotenuse = straight+1;
                straight++;
            }
            int numColums = straight + hypotenuse*middle;
            int pos = 0;

            char array[numRows][numColums];

            for (int j = 0; j < numColums; j++)
            {
                for (int i = 0; i < numRows; i++)
                {
                    if (0 == j%(numRows-1))
                    {
                        if (pos < length)
                        {
                            array[i][j] = s[pos];
                            pos++;
                        }
                        else
                        {
                            // make every position is null, no arbitrary value
                            array[i][j] = '\0';
                        }

                    }
                    else
                    {
                        if ( 0 == (i+j)%(numRows-1))
                        {
                            if (pos < length)
                            {
                                array[i][j] = s[pos];
                                pos++;
                            }
                            else
                            {
                                // make every position is null, no arbitrary value
                                array[i][j] = '\0';
                            }
                        }
                        else
                        {
                            // make every position is null, no arbitrary value
                            array[i][j] = '\0';
                        }
                    }
                }
            }

            // convert char[][] to string
            string result;
            int temp = 0;
            for (int i = 0; i < numRows; i++)
            {
                for (int j = 0; j < numColums; j++)
                {
                    if (temp < length)
                    {
                        if ('\0' == array[i][j])
                        {
                            continue;
                        }
                        else
                        {
                            result += array[i][j];
                            temp++;
                        }
                    }
                    else
                    {
                        return result;
                    }
                }
            }
            return result;
        }

    }
};


int main ()
{
    //string s = "txkrsdyronxiisbacxkdczwdlevfughpftgxzhpnuoxegagixsnbujffpcmkivbpoimnrddnrcuzdakatxcnjjsangmxbomryahpekexmyzrzjsuiwjrfduujgrkuddsfkjjwqjjoiaptulbquvxxprgvksqnwktiwefmpqczsusnfufarfxgygbjatywgthcamqpcsrumjjufpuwwteubifcbeajzhnzvdrxyismtdgbscxqyclzksdnwgzypmxlsqisaceuglvapurnyepkwuavaztqnsbhjlzjoefurcwgznwxtliqfklileyywbihmhtanywebvnakjzewjudthlenlflontbumdimcopxbrhmrlkahqwqdafphrfumgrakzmmpclttshmgsnpilgllncteipqqgschfoxjbqcuzrcrerbrzpcnrxtbpmsveudjlcsmuxitoknueonfdpsxpmaeyubepgociiqehbyxlltrbgxfypepdevdzwiqdyungksqlqnzdjqepnlpfrekwzoxwynbwjqetiuhakidtykkoxavpefngvketzfpivudgqkgasmvtygjxiemmjzuhlyakfsudoyjekrhffcydkjbsnphyrdfcciphajkojvsunbzsezyqiblvquvjxbobjdjjovzyrruettyzswraxexqyszyvnzgsirjeqjxkdbfwzeqyxqxcpnchpafcclxkdgqtpndsqkqsqgqoynsnduwsxbwznvlsbensttmkdceukuiijaxowugtxfukageeksydllpontiansizuinrcwmbdhofnslzkkcvvsmknukdpvcjdrchppiuyyalrlmbxqzsilfyhpbwmdgrwiaozjixhikawwctndoxotvvkwsxbaoyipmiaufjfqmdooybtmzhfwestwpuwfuhwi";
    //string s = "ABC";
    string s = "A";
    string result;
    Solution solution;
    result = solution.convert(s,3);



    std::cout << result << std::endl;
    std::system("pause");
    return 0;
}





