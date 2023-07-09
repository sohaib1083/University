#include <bits/stdc++.h>
using namespace std;
#define f 4 // number of frames

void printStack(int s[], int top)
{
    for (int i = 0; i <= top; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

int main(void)
{

    int stack_s[f];
    int top = -1;
    int cnt = 0;
    vector <int> s = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = 13;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int c = s[i];
        //cout << c << " ";

        if (mp.find(c) == mp.end()) // nhi mila
        {
            if (top < f - 1)
            {
                top++;
                stack_s[top] = c;
            }
            else
            {
                // remove last element
                for (int i = 0; i < top; i++)
                {
                    stack_s[i] = stack_s[i + 1];
                }
                stack_s[top] = c;
                mp.erase(stack_s[top]);
            }
            cnt++;
            mp[c]=1;
        }
        else
        { // bring it to the top
            //find
            int i = top;
            while (stack_s[i] != c){
                i--;
            }

            // now swap locations
            for (int j=i; j<top; j++){
                stack_s[j]=stack_s[j+1];
            }
            stack_s[top]=c;
        }

        printStack(stack_s, top);
    }

    cout << "The number of page faults: " << cnt;

}
