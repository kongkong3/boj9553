#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double get_angle(int x1, int y1, int x2, int y2);
int main()
{
    int test_case_num;
    cin >> test_case_num;
    vector<double> probability_container{};
    for(int i = 0; i < test_case_num; i++)
    {
        int target_num;
        double probability = 0;
        cin >> target_num;
        for(int j = 0; j < target_num; j++)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            probability += get_angle(x1, y1, x2, y2) / (2 * M_PI);
        }
        probability_container.push_back((round(probability * pow(10, 5))) / (pow(10, 5)));
    }
    for(double i : probability_container)
    {
        cout << i << "\n";
    }
    return 0;
}
double get_angle(int x1, int y1, int x2, int y2) /// atan2 함수를 이용해서 두 점 사이의 각도를 구하는 함수
{
   if(atan2(y1 * x2 - x1 * y2, x1 * x2 + y1 * y2) < 0)
   {
       return -atan2(y1 * x2 - x1 * y2, x1 * x2 + y1 * y2);
   }
   else
   {
       return atan2(y1 * x2 - x1 * y2, x1 * x2 + y1 * y2);
   }
}
