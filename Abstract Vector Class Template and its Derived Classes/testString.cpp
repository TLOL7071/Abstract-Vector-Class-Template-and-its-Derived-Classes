#include <iostream>
#include "String.h"
#include <cstring>
using namespace std;

void testStringFunctions() {
    String str1, str2, result;
    int choice;

    do {
        cout << "ÇëÑ¡ÔñÒª²âÊÔµÄ¹¦ÄÜ£º" << endl;
        cout << "1. ÊäÈë×Ö·û´®" << endl;
        cout << "2. Êä³ö×Ö·û´®" << endl;
        cout << "3. ²åÈë×Ö·û´®" << endl;
        cout << "4. ²éÕÒ×Ö·û´®" << endl;
        cout << "5. ×Ö·û´®Æ´½Ó" << endl;
        cout << "6. Çå¿Õ×Ö·û´®" << endl;
        cout << "0. ÍË³ö" << endl;
        cout << "ÊäÈëÄãµÄÑ¡Ôñ: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "ÇëÊäÈëÒ»¸ö×Ö·û´®: ";
            cin >> str1;
            break;

        case 2:
            cout << "µ±Ç°×Ö·û´®Îª: ";
            str1.Output(cout);
            cout << endl;
            break;

        case 3: {
            char insertStr[1024];
            cout << "ÇëÊäÈëÒª²åÈëµÄ×Ö·û´®: ";
            cin >> insertStr;
            cout << "size:" << strlen(insertStr) << " " << str1.length() << endl;
            int position;
            cout << "ÇëÊäÈë²åÈëÎ»ÖÃ: ";
            cin >> position;
            str1.insert(position, insertStr);
            cout << "²åÈëºóµÄ×Ö·û´®£º" << endl;
            cout << str1 << endl;
            cout << "size:" << str1.length() << endl;
            break;
        }

        case 4: {
            char findStr[1024];
            cout << "ÇëÊäÈëÒª²éÕÒµÄ×Ö·û´®: ";
            cin >> findStr;
            String strToFind(findStr);
            int position = str1.find(strToFind);
            if (position != -1) {
                cout << "×Ö·û´® '" << findStr << "' ÔÚÎ»ÖÃ " << position << " ÕÒµ½¡£" << endl;
            }
            else {
                cout << "×Ö·û´® '" << findStr << "' Î´ÕÒµ½¡£" << endl;
            }
            break;
        }

        case 5: {
            char appendStr[1024];
            cout << "ÇëÊäÈëÒªÆ´½ÓµÄ×Ö·û´®: ";
            cin >> appendStr;
            str1.append(appendStr);
            cout << "Æ´½ÓºóµÄ×Ö·û´®Îª: ";
            str1.Output(cout);
            cout << endl;
            break;
        }

        case 6:
            str1.clear();
			cout << "str1=\""<< str1 << "\"" << endl;
            cout << "×Ö·û´®ÒÑÇå¿Õ¡£" << endl;
            break;

        case 0:
            cout << "ÍË³ö³ÌÐò¡£" << endl;
            break;

        default:
            cout << "ÎÞÐ§µÄÑ¡Ôñ£¬ÇëÖØÐÂÊäÈë¡£" << endl;
        }
    } while (choice != 0);
}

int main() {
    testStringFunctions();
	/*string str1("hello");
	string str2("world");
	string str3 = str1 + str2;
	cout << str3 << endl;*/

    return 0;
}