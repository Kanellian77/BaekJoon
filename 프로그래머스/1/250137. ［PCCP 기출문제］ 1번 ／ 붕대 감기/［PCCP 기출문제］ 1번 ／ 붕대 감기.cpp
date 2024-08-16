#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int t = bandage[0], x = bandage[1], y = bandage[2];
    int maxhealth = health;
    int maxit = attacks[attacks.size()-1][0];
    int conti = 0;
    int attacki = 0;
    
    for(int i = 1; i <= maxit ; i++)
    {
        //우선 쳐맞는게 있는가?
        if(i==attacks[attacki][0])
        {
            health = health-attacks[attacki][1];
            // 0이하일때 보내줌
            if(health<=0)
            {
                health = -1;
                break;
            }
            attacki++;
            conti = 0;
        }
        else
        {
            health = health + x;
            if(health>= maxhealth)
            {
                health = maxhealth;
            }
            conti++;

            if(conti == t)
            {
                health = health + y;
                if(health>= maxhealth)
                {
                    health = maxhealth;
                }
                conti = 0;
            }
            
        }
       
        
    }
    return health;
}