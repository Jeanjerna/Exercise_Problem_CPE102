#include <iostream>
using namespace std;

double TimeFire(double r)
{
    return r/10;
}

int main()
{
    double locate , Save_locate , Farleft , FarRight , time , range = 0 , MaxRange;

    cout << "Input the burner location: ";
    cin >> locate;
    Save_locate = locate;
    Farleft = locate;

    if (locate == 100) time = TimeFire(100);
    else
    {
        while (true)
        {
            cout << "Input the burner location: ";
            cin >> locate;

            if (locate < 0 or locate > 100)
            {
                FarRight = 100 - Save_locate;
                break;
            }
            else
            {
                if(locate <= Save_locate)
                {
                    cout << "Next location must be greater than " << Save_locate << endl;
                    continue;
                }
                else
                {
                        if ((locate - Save_locate)/2 > range) range = (locate - Save_locate)/2;
                        if (locate == 100)
                        {
                            // FarRight = (100 - Save_locate)/2;
                            // break;

                            // แบบนี้ดีกว่าให้ FarRight เป็น 0 แล้วก็ให้ทุกอย่างคำนวนใน range เอา ถ้าแบบข้างบน range จะเท่ากับ FarRight
                            FarRight = 0;
                            break;
                        }

                        Save_locate = locate;
                }
            }
        }

        if (Farleft >= FarRight and Farleft >= range) MaxRange = Farleft;
        else if (FarRight >= Farleft and FarRight >= range) MaxRange = FarRight;
        else MaxRange = range;

        // ทำหรับเช็คความภูกต้องของตัวแปล
        // cout << "FarLeft : " << Farleft << endl;
        // cout << "FarRight : " << FarRight << endl;
        // cout << "range : " << range << endl;
        // cout << "Max : " << MaxRange << endl;

        time = TimeFire(MaxRange) ;
    }


    cout << time;

}