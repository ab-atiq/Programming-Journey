#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int Q;
    cin >> Q;
    stack<int> machine;
    long long sum = 0;

    while (Q--)
    {
        int command;
        cin >> command;

        if (command == 1)
        {
            cout << sum << "\n";
        }
        else if (command == 2)
        {
            int X;
            cin >> X;
            machine.push(X);
            sum += X;
        }
        else if (command == 3)
        {
            if (!machine.empty())
            {
                sum -= machine.top();
                machine.pop();
            }
        }
    }

    return 0;
}
