class Solution {
public:
    string digitSum(string s, int k) {
        if (s.length() <= k) {
            return s;
        }

        while (s.length() > k) {
            string sb = "";
            int idx = 0;
            int sum = 0;

            for (int i = 0; i < s.length(); i++) {
                if (i / k != idx) {
                    sb += to_string(sum);
                    sum = 0;
                    idx++;
                }

                sum += s[i] - '0';
            }

            sb += to_string(sum);
            s = sb;
        }

        return s;
    }
};