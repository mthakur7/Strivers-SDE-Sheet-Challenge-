/*
    Time Complexity     :   O(N)
    Space Complexity    :   O(1)

    Where 'N' is the length of the string.
*/

#include<unordered_map>

int romanToInt(string s) {
    int count = 0;

    // To store previous char value.
    int preInt = 0;

    // Unordered map for finding interger value for roman numerals.
    unordered_map<char, int> conv =
        {{'I', 1},
         {'V', 5},
         {'X', 10},
         {'L', 50},
         {'C', 100},
         {'D', 500},
         {'M', 1000}};

    // Loop from end to start of the string.
    for (int i = s.length() - 1; i >= 0; i--) {
        char ch = s[i];

        // Store current char integer value.
        int curInt = conv[ch];

        /*
            If current value is greater or equal to previous value then increment count i.e., II means 1+1
            else in case of IV, V = 5 and I = 1 here 1 < 5 then else part will execute and update count as 5 - 1 = 4.
        */
        if (curInt >= preInt) {
            count += curInt;
        } else {
            count -= curInt;
        }

        // Update 'preInt' value with current value for next iteration.
        preInt = curInt;
    }
    return count;
}
