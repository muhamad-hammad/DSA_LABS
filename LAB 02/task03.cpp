// 3. Write a program that creates a 2D array of 5x5 values of type Boolean. Suppose indices
// represent people and the value at row i, column j of a 2D array is true just in case i and j are friends and
// false otherwise. You can use initializer list to instantiate and initialize your array to represent the
// following configuration: (* means “friends”)
// i/j 0 1 2 3 4
// 0     *   * *
// 1   *   *   *
// 2     *
// 3   *       *
// 4   * *   *
// Write a method to check whether two people have a common friend. For example, in the example above,

#include <iostream>
using namespace std;

class task03
{

private:
    bool friends[5][5] = {
        //   0  1  2  3  4
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 0}};

public:
    int i, j;
    task03()
    {
        cout << "Enter two people's numbers: ";
        cout << "Enter first person's number: ";
        cin >> i;
        cout << "Enter second person's number: ";
        cin >> j;
    }

    void ifFriend(int i, int j)
    {
        bool flag = 0;
        for (int k = 0; k < 5; k++)
        {
            if (friends[i][k] && friends[j][k])
            {
                cout << "They both( " << i << " " << j << " ) have a common friend : " << k << endl;
                flag = 1;
            }
            else if (k == 5 && flag == 0)
            {
                cout << "They both( " << i << " " << j << " ) don't have a common friend" << endl;
            }
        }
    }
};

int main()
{
    task03 t;
    t.ifFriend(t.i, t.j);
    return 0;
}