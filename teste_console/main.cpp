#include <iostream>
#include <gpp/gpp.h>
#include <gpp_physics/gpp_physics.h>
#include <cmath>

using namespace gpp;
using namespace std;

void printMT(int mt[3][3]);

int main()
{
    setlocale(LC_ALL, "Portuguese");
cout<<fixed;
    const float angle = -90.0f * (GPP_PI / 180.0f);
    quaternion rotation = quaternion(1.0f, 0.0f, sin(angle / 2), cos(angle / 2));
    int mt1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mt2[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    printMT(mt1);
    for (int i = 0; i < 3; i++)
    {
        for (int i1 = 0; i1 < 3; i1++)
        {
            vector3d v((float)i - 1, (float)i1 - 1, 0);
            vector3d rf = quaternion_vector_rotate(rotation, v);
            int x = floor(rf.x + 1.5f);
            int y = floor(rf.y + 1.5f);
                mt2[x][y] = mt1[i][i1];
        }
    }
    printMT(mt2);
    return 0;
}

void printMT(int mt[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int i1 = 0; i1 < 3; i1++)
        {
            cout << mt[i][i1] << " ";
        }
        cout << endl;
    }
}
