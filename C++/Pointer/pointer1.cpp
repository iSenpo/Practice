#include <iostream>
#include <cctype>

using namespace std;

int my_strlen(char *s)
{
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
void to_uppercase(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = toupper(s[i]);
    }
}
void reverse_string(char *s)
{
    char *left = s;
    char *right = s;
    while (*right != '\0')
    {
        right++;
    }
    right--;
    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}
/* int count_substring(char *s, char *sub) {
    int counter = 0;
    int sub_len = my_strlen(sub);
    int s_len = my_strlen(s);

    if (sub_len == 0 || sub_len > s_len) return 0;

    for (int i = 0; i <= s_len - sub_len; i++) {
        bool match = true;
        for (int j = 0; j < sub_len; j++) {
            if (s[i + j] != sub[j]) {
                match = false;
                break;
            }                   WTF!
        }
        if (match) counter++;
    }
    return counter;
} */
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    cin.ignore();
    char *ptr = new char[n + 1];
    char *sub = new char[m + 1];

    cin.get(sub, m + 1);
    cin.ignore();

    cin.get(ptr, n + 1);
    cout << my_strlen(ptr) << "\n";

    to_uppercase(ptr);
    cout << ptr << "\n";

    reverse_string(ptr);
    cout << ptr << "\n";

    // cout<<count_substring(ptr,sub);
    delete[] ptr;
    return 0;
}