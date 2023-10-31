/*
n == date.length()
runtime: O(n)
space: O(n)
*/
class Solution {
    string parse_month(string& s) {
        if (s == "Jan") return "01";
        if (s == "Feb") return "02";
        if (s == "Mar") return "03";
        if (s == "Apr") return "04";
        if (s == "May") return "05";
        if (s == "Jun") return "06";
        if (s == "Jul") return "07";
        if (s == "Aug") return "08";
        if (s == "Sep") return "09";
        if (s == "Oct") return "10";
        if (s == "Nov") return "11";
        if (s == "Dec") return "12";
        return "";  // error
    }

public:
    string reformatDate(string date) {
        int n = date.length();
        int i = 0;

        string day_str;
        while (i < n) {
            if (isdigit(date[i])) day_str += date[i];
            else break;
            i++;
        }
        while (date[i] != ' ') i++;
        i++;

        string month_str;
        while (i < n) {
            if (isalpha(date[i])) month_str += date[i];
            else break;
            i++;
        }
        i++;

        string year_str;
        while (i < n) {
            if (isdigit(date[i])) year_str += date[i];
            i++;
        }

        if (day_str.length() < 2) day_str.insert(0, 1, '0');  // zero padding

        string month = parse_month(month_str);
        return year_str + '-' + month + '-' + day_str;
    }
};
