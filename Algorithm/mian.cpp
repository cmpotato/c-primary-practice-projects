
#include"method.h"

struct ListNode {
	int val;
	struct ListNode* next;
};

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strs[0][0] == 0)
    {
        return strs[0];
    }

    char* com = (char*)malloc(sizeof(char) * 200);
    memset(com, 0, sizeof(char) * 200);
    int i = 0;
    while (strs[0][i])
    {
        com[i] = strs[0][i];
        i++;
    }

    int j = 1;
    i = 0;
    for (j = 1; j < strsSize; j++)
    {
        for (i = 0; i < 200; i++)
        {

            if (com[i] == strs[j][i])
            {
                continue;
            }
            else
            {
                com[i] = 0;
                break;
            }
        }
    }
    return com;
}


int main() {

    char a[] = "flower";
    char b[] = "flower";
    char c[] = "flower";
    char d[] = "flower";
    char* strs[] = {a, b, c, d};
    char* com = longestCommonPrefix(strs, 4);
    
    cout << com;
    
	return 0;
}

