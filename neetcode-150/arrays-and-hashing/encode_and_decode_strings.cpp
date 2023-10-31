/*
n == strs.size()
k == strs[0].length()
runtime: O(n*k)
space: O(k)
*/
class Codec {
    string DELIMITER = "@%*@^#*&@^&*$^*@&#%$*";

public:
    string encode(vector<string>& strs) {
        stringstream encoded;
        for (const auto& s : strs) {
            encoded << s << DELIMITER;
        }
        return encoded.str();
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        string curr;
        for (int i = 0; i < s.length(); i++) {
            if (s.substr(i, DELIMITER.length()) == DELIMITER) {
                decoded.push_back(curr);
                curr.clear();

                i += DELIMITER.length();
                i--;  // counteract i++
            } else {
                curr += s[i];
            }
        }
        return decoded;
    }
};

/*
FOLLOW UP
n == strs.size()
k == strs[0].length()
runtime: O(n*k)
space: O(k)
*/
class Codec {
    string DELIMITER = "/$";

public:
    string encode(vector<string>& strs) {
        stringstream encoded;
        for (const auto& s : strs) {
            string new_str;
            for (char ch : s) {
                if (ch == '/') new_str += "//";
                else new_str += ch;
            }
            new_str += DELIMITER;

            encoded << new_str;
        }
        return encoded.str();
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        string curr;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && s[i] == '/' && s[i + 1] == '/') {
                curr += '/';
                i++;
            } else if (i < s.length() - 1 && s[i] == '/' && s[i + 1] == '$') {
                decoded.push_back(curr);
                curr.clear();

                i += DELIMITER.length();
                i--;  // counteract i++
            } else {
                curr += s[i];
            }
        }
        return decoded;
    }
};

/*
FOLLOW UP
USED SOLUTION
n == strs.size()
k == strs[0].length()
runtime: O(n*k)
space: O(k)
*/
class Codec {
    char DELIMITER = ';';

public:
    string encode(vector<string>& strs) {
        stringstream encoded;
        for (const auto& s : strs) {
            int len = s.length();
            encoded << len << DELIMITER << s;
        }
        return encoded.str();
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i = 0;
        while (i < s.length()) {
            string len_str;
            while (s[i] != DELIMITER) {
                len_str += s[i];
                i++;
            }
            i++;  // move past delimiter

            int len = stoi(len_str);
            string curr = s.substr(i, len);
            decoded.push_back(curr);
            i += len;
        }
        return decoded;
    }
};
