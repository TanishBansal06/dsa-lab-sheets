//a))
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str1 = "Hello ";
    string str2 = "World";

    string result = str1 + str2;  

    cout << "Concatenated string: " << result << endl;
    return 0;
}
//b))
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str = "OpenAI";

    reverse(str.begin(), str.end());

    cout << "Reversed string: " << str << endl;
    return 0;
}
//c))
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}


int main() {
    string str = "Beautiful Day";
    string result = "";

    for (char c : str) {
        if (!isVowel(c)) {
            result += c;
        }
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}

//d))
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string arr[] = {"Banana", "Apple", "Mango", "Cherry"};
    int n = 4;
    sort(arr, arr + n);
   cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
//e))
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch = 'A';

    char lower = tolower(ch);

    cout << "Lowercase: " << lower << endl;
    return 0;
}
