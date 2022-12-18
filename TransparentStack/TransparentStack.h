#include <iostream>
#include <vector>

using namespace std;

class RedBlackTree : public stack
{
public:
    T peek_at(int idx)
    {
        if (!empty())
        {
            for (int i=0;i<c.size();i++)
            {
                if (i==idx)
                {
                    return c.at(idx);
                }
            }
            
        }
        return nullptr;
    }

private:
}
