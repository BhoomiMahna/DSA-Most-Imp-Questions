class Solution {
    int last_palindrome_end = -1;

    pair<int, int> expandCenter(int l, int r, string &s, int k) {
        int n = s.size();

        while(l > last_palindrome_end && r < n) {

            if(s[l] != s[r])
                break;

            if(r - l + 1 >= k)
                return {r - l + 1, r};

            l--;
            r++;
        }

        return {-1, -1};
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        if(k == 1)
            return n;

        int count = 0;
        int i = 0;

        while(i < n) {

            auto l1 = expandCenter(i, i, s, k);

            auto l2 = make_pair(-1, -1);

            if(i + 1 < n)
                l2 = expandCenter(i, i + 1, s, k);

            if(l1.first == -1 && l2.first == -1) {
                i++;
                continue;
            }

            if(l1.first != -1 && l2.first != -1) {
                if(l1.second > l2.second)
                    swap(l1, l2);
            }
            else {
                if(l1.first == -1)
                    swap(l1, l2);
            }

            last_palindrome_end = l1.second;

            i = last_palindrome_end + 1;

            count++;
        }

        return count;
    }
};
